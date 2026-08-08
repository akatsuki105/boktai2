	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	bl FUN_0823e850
	ldr r3, _0823F40C @ =0x00000000
	ldr r2, _0823F408 @ =0x3FE00000
	bl __adddf3
	adds r7, r1, #0
	adds r6, r0, #0
	str r6, [sp]
	str r7, [sp, #4]
	movs r0, #1
	mov r8, r0
	b _0823F450
	.align 2, 0
_0823F408: .4byte 0x3FE00000
_0823F40C: .4byte 0x00000000
_0823F410:
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r3, _0823F510 @ =0x00000000
	ldr r2, _0823F50C @ =0x00000000
	bl __ltdf2
	cmp r0, #0
	bge _0823F430
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F514 @ =0xBFB99999
	ldr r3, _0823F518 @ =0x9999999A
	bl __gedf2
	cmp r0, #0
	bge _0823F496
_0823F430:
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F51C @ =0x40285D14
	ldr r3, _0823F520 @ =0xE3BCD35B
	bl __divdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	movs r0, #1
	add r8, r0
_0823F450:
	mov r0, r8
	cmp r0, #6
	bgt _0823F496
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0823ea00
	adds r5, r1, #0
	adds r4, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0823f210
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r3, _0823F510 @ =0x00000000
	ldr r2, _0823F50C @ =0x00000000
	bl __gedf2
	cmp r0, #0
	blt _0823F410
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F524 @ =0x3FB99999
	ldr r3, _0823F528 @ =0x9999999A
	bl __ledf2
	cmp r0, #0
	bgt _0823F410
_0823F496:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r3, _0823F510 @ =0x00000000
	ldr r2, _0823F50C @ =0x00000000
	bl __ltdf2
	cmp r0, #0
	blt _0823F4C4
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F52C @ =0x403D8D62
	ldr r3, _0823F530 @ =0x69BD25B0
	bl __gtdf2
	cmp r0, #0
	bgt _0823F4C4
	b _0823F5DA
_0823F4C4:
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r3, _0823F510 @ =0x00000000
	ldr r2, _0823F50C @ =0x00000000
	bl __ltdf2
	cmp r0, #0
	bge _0823F534
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, _0823F52C @ =0x403D8D62
	ldr r3, _0823F530 @ =0x69BD25B0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, _0823F52C @ =0x403D8D62
	ldr r1, _0823F530 @ =0x69BD25B0
	bl __negdf2
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __ltdf2
	cmp r0, #0
	bge _0823F544
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, _0823F52C @ =0x403D8D62
	ldr r3, _0823F530 @ =0x69BD25B0
	bl __subdf3
	b _0823F540
	.align 2, 0
_0823F50C: .4byte 0x00000000
_0823F510: .4byte 0x00000000
_0823F514: .4byte 0xBFB99999
_0823F518: .4byte 0x9999999A
_0823F51C: .4byte 0x40285D14
_0823F520: .4byte 0xE3BCD35B
_0823F524: .4byte 0x3FB99999
_0823F528: .4byte 0x9999999A
_0823F52C: .4byte 0x403D8D62
_0823F530: .4byte 0x69BD25B0
_0823F534:
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r3, _0823F550 @ =0x69BD25B0
	ldr r2, _0823F54C @ =0x403D8D62
	bl __adddf3
_0823F540:
	adds r7, r1, #0
	adds r6, r0, #0
_0823F544:
	movs r0, #1
	mov r8, r0
	b _0823F594
	.align 2, 0
_0823F54C: .4byte 0x403D8D62
_0823F550: .4byte 0x69BD25B0
_0823F554:
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r3, _0823F5FC @ =0x00000000
	ldr r2, _0823F5F8 @ =0x00000000
	bl __ltdf2
	cmp r0, #0
	bge _0823F574
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F600 @ =0xBFB99999
	ldr r3, _0823F604 @ =0x9999999A
	bl __gedf2
	cmp r0, #0
	bge _0823F5DA
_0823F574:
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F608 @ =0x40285D14
	ldr r3, _0823F60C @ =0xE3BCD35B
	bl __divdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl __subdf3
	adds r7, r1, #0
	adds r6, r0, #0
	movs r0, #1
	add r8, r0
_0823F594:
	mov r0, r8
	cmp r0, #4
	bgt _0823F5DA
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0823ea00
	adds r5, r1, #0
	adds r4, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0823f210
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r3, _0823F5FC @ =0x00000000
	ldr r2, _0823F5F8 @ =0x00000000
	bl __gedf2
	cmp r0, #0
	blt _0823F554
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F610 @ =0x3FB99999
	ldr r3, _0823F614 @ =0x9999999A
	bl __ledf2
	cmp r0, #0
	bgt _0823F554
_0823F5DA:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r7, #0
	adds r2, r6, #0
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r2}
	bx r2
	.align 2, 0
_0823F5F8: .4byte 0x00000000
_0823F5FC: .4byte 0x00000000
_0823F600: .4byte 0xBFB99999
_0823F604: .4byte 0x9999999A
_0823F608: .4byte 0x40285D14
_0823F60C: .4byte 0xE3BCD35B
_0823F610: .4byte 0x3FB99999
_0823F614: .4byte 0x9999999A
