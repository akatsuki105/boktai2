	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	mov r8, r3
	ldr r0, _08013BD4 @ =0x03000054
	ldr r7, [r0]
	cmp r7, #0
	bne _08013BD8
	movs r0, #0
	movs r1, #0
	bl Entity08013b68_Create
	adds r7, r0, #0
	cmp r7, #0
	bne _08013BD8
	movs r0, #1
	rsbs r0, r0, #0
	b _08013C58
	.align 2, 0
_08013BD4: .4byte 0x03000054
_08013BD8:
	movs r1, #0
	strb r1, [r6]
	str r4, [r6, #8]
	ldr r0, [sp, #0x30]
	strb r0, [r6, #1]
	strb r1, [r6, #2]
	strh r1, [r6, #4]
	strh r1, [r6, #6]
	adds r0, r6, #0
	adds r0, #0x54
	strb r5, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x56
	ldr r0, [sp, #0x18]
	strb r0, [r1]
	adds r1, #1
	ldr r0, [sp, #0x1c]
	strb r0, [r1]
	adds r1, #1
	ldr r0, [sp, #0x20]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x24]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x28]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x2c]
	strh r0, [r1]
	ldrb r0, [r6, #1]
	cmp r0, #0
	bne _08013C28
	ldr r0, _08013C24 @ =FUN_080139b8
	b _08013C2A
	.align 2, 0
_08013C24: .4byte FUN_080139b8
_08013C28:
	ldr r0, _08013C64 @ =nop_080139b4
_08013C2A:
	str r0, [r6, #0x60]
	adds r5, r6, #0
	adds r5, #0x38
	ldr r1, _08013C68 @ =0x00001C1B
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r4, r6, #0
	adds r4, #0xc
	ldr r2, _08013C6C @ =0x00000202
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a470
	movs r0, #5
	strh r0, [r4, #0x10]
	movs r0, #2
	strb r0, [r6, #0x13]
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_0801392c
	movs r0, #0
_08013C58:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08013C64: .4byte nop_080139b4
_08013C68: .4byte 0x00001C1B
_08013C6C: .4byte 0x00000202
