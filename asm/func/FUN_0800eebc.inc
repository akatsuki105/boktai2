	push {lr}
	sub sp, #0x18
	adds r3, r0, #0
	adds r0, #0x60
	ldr r2, _0800EF04 @ =0xFFFF0000
	adds r1, r3, #0
	adds r1, #0x62
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	ldrh r0, [r0]
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r3, #0
	adds r0, #0x64
	ldrh r1, [r0]
	ldr r0, [sp, #0x14]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r0, #8
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015d3c
	add sp, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_0800EF04: .4byte 0xFFFF0000
