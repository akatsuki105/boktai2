	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r0, #1
	str r0, [sp, #0x2c]
	ldr r0, _080BA844 @ =0x0000140E
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, r5, r0
	ldr r2, _080BA848 @ =0x000012E4
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x68
	str r0, [sp, #0x34]
	ldr r0, _080BA84C @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	ldrb r1, [r1]
	add r0, sp, #0xc
	bl FUN_080b9938
	add r4, sp, #0x1c
	ldr r1, _080BA850 @ =0x0000140B
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080b9938
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	movs r0, #0x68
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
	ldr r2, _080BA854 @ =0x00001314
	adds r5, r5, r2
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _080BA858 @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BA844: .4byte 0x0000140E
_080BA848: .4byte 0x000012E4
_080BA84C: .4byte 0x000002DF
_080BA850: .4byte 0x0000140B
_080BA854: .4byte 0x00001314
_080BA858: .4byte 0x0000038A
