<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the website, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/documentation/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', getenv('DATABASE_NAME'));

/** Database username */
define( 'DB_USER', getenv('DATABASE_USER'));

/** Database password */
define( 'DB_PASSWORD', getenv('DATABASE_PASSWORD'));

/** Database hostname */
define( 'DB_HOST', getenv('DATABASE_HOST'));

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
/**#@-*/
define('AUTH_KEY',         'Z{ilqtYTr%xp#JfU}@C4QLgNEmTIy+cXTD<ueWc-+:b5():m0$se+_]4.x-12S%{');
define('SECURE_AUTH_KEY',  '4Xohs`?[d#V; q$:N54Yje5w<lZ5pLOS&D}fHC_qX2K;*BDMEEx|>`H_IsM~3f>+');
define('LOGGED_IN_KEY',    'GFW8+W,F-^[iA>4p~I;LlHjp4h ~9B8S#7|Ns7YLeC,g|?[2<h:W&Z7L|b*i,l|C');
define('NONCE_KEY',        'D^7UZ!H-U4:j<-F`|!)}Op@mHB Lj&um]qhJ[PM4#6+K6+n]VZ~B^M;^#,fb<dlt');
define('AUTH_SALT',        '#NtAb~/C-4`R9J,$0X Zq}7|_JT.rC.`?!Q G+Vzd)+X-Q;5hG@C-ZY>W7ehqoP9');
define('SECURE_AUTH_SALT', 'kN18ekX:v/xZ?61*)q9P6zYz|^Z8N,&PX@ZDQ;s>%^~23H*hlz|ZIzS@459^}7|;');
define('LOGGED_IN_SALT',   '-vL~jS $Fe.#A3n#}]dC~$)%e]k||bJU<|Rz-2|id:kS%l6YQZ#h8% P-uFxMfeE');
define('NONCE_SALT',       'lWC gloCIB2@>BgUN@&8YY8+<Ps~[}(1/VKeZ#J`jtgR_&_EF!A[~x4YD1^BNH/!');
/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/documentation/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */



/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
