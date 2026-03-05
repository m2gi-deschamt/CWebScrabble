# ------------------------------
# Étape 2 : serveur Apache
# ------------------------------
FROM httpd:2.4

COPY --from=build-stage /app/dist /app/.htaccess /usr/local/apache2/htdocs/

RUN sed -i \
    -e 's/^#\(LoadModule .*mod_rewrite.so\)/\1/' \
    -e 's/^#\(LoadModule .*mod_ssl.so\)/\1/' \
    -e 's/^#\(LoadModule .*mod_socache_shmcb.so\)/\1/' \
    -e 's/^#\(Include .*httpd-ssl.conf\)/\1/' \
    /usr/local/apache2/conf/httpd.conf

RUN echo "ServerName localhost" >> /usr/local/apache2/conf/httpd.conf

COPY ./webellion.conf /usr/local/apache2/conf/extra/webellion.conf
RUN echo "Include conf/extra/webellion.conf" >> /usr/local/apache2/conf/httpd.conf

EXPOSE 80 443