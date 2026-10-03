	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r4, r0, #0
	movs r0, #1
	str r0, [sp, #0x2c]
	ldr r0, _080BD6B4 @ =0x0000178A
	adds r2, r4, r0
	ldr r1, _080BD6B8 @ =0x00001654
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #4
	subs r0, #0x10
	ldrb r3, [r2]
	adds r0, r0, r3
	ldr r3, _080BD6BC @ =0x0000165C
	adds r1, r4, r3
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	str r0, [sp, #0x34]
	ldr r0, _080BD6C0 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r2]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r5, sp, #0x1c
	ldr r1, _080BD6C4 @ =0x00001787
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	add r6, sp, #0x34
	str r2, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r5, #8]
	strh r2, [r5, #0xa]
	strh r2, [r5, #0xc]
	ldr r0, _080BD6C8 @ =0x00001690
	adds r4, r4, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	add r2, sp, #0xc
	adds r3, r5, #0
	bl FUN_080b9a28
	ldr r0, _080BD6CC @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BD6B4: .4byte 0x0000178A
_080BD6B8: .4byte 0x00001654
_080BD6BC: .4byte 0x0000165C
_080BD6C0: .4byte 0x000002DF
_080BD6C4: .4byte 0x00001787
_080BD6C8: .4byte 0x00001690
_080BD6CC: .4byte 0x0000038A
