	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r4, #1
	str r4, [sp, #0x2c]
	ldr r0, _080BB83C @ =0x0000140E
	adds r3, r5, r0
	ldrb r0, [r3]
	adds r0, #3
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r2, r5, #0
	adds r2, #0x80
	adds r2, r2, r1
	ldr r0, [r2]
	orrs r0, r4
	str r0, [r2]
	ldrb r0, [r3]
	ldr r1, _080BB840 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r0, #0x43
	str r0, [sp, #0x34]
	ldr r0, _080BB844 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r3]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	ldr r1, _080BB848 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x43
	add r6, sp, #0x34
	str r0, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r4, #8]
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	ldr r0, _080BB84C @ =0x00001314
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080BB850 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BB83C: .4byte 0x0000140E
_080BB840: .4byte 0x030046A0
_080BB844: .4byte 0x000002DF
_080BB848: .4byte 0x0000140B
_080BB84C: .4byte 0x00001314
_080BB850: .4byte 0x0000038A
