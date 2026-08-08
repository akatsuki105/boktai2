	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r5, r4, r0
	ldr r2, _0807E374 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x78
	orrs r0, r3
	ldr r1, _0807E378 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldr r2, _0807E37C @ =0x00002001
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #0x80
	lsls r0, r0, #9
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #0x28
	movs r3, #0
	bl FUN_082364f8
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823651c
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r0, _0807E380 @ =0x000002EB
	adds r1, r4, r0
	movs r0, #6
	strb r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r1, _0807E384 @ =0x0000032E
	adds r4, r4, r1
	strb r0, [r4]
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807E374: .4byte 0xFFFF0000
_0807E378: .4byte 0x0000FFFF
_0807E37C: .4byte 0x00002001
_0807E380: .4byte 0x000002EB
_0807E384: .4byte 0x0000032E
