	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x9c
	ldr r2, _0807FF60 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	ldr r3, _0807FF64 @ =0x00007530
	orrs r0, r3
	ldr r1, _0807FF68 @ =0x0000FFFF
	ands r0, r1
	ldr r1, _0807FF6C @ =0x75300000
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldr r2, _0807FF70 @ =0x00003001
	ldr r1, [r4, #0x18]
	adds r1, #0x28
	movs r0, #0x80
	lsls r0, r0, #9
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, [r4, #0x18]
	ldr r1, _0807FF74 @ =0x00000366
	adds r0, r0, r1
	ldrh r1, [r0]
	lsrs r1, r1, #1
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	movs r0, #0x32
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x32
	movs r3, #0
	bl FUN_082364f8
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r1, [r4, #0x18]
	adds r1, #0x2c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807FF60: .4byte 0xFFFF0000
_0807FF64: .4byte 0x00007530
_0807FF68: .4byte 0x0000FFFF
_0807FF6C: .4byte 0x75300000
_0807FF70: .4byte 0x00003001
_0807FF74: .4byte 0x00000366
