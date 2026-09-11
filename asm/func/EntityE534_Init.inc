	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	movs r1, #0
	str r1, [r6, #0x18]
	ldr r2, _08012C0C @ =0x00000CA6
	adds r0, r6, r2
	strh r1, [r0]
	ldr r3, _08012C10 @ =0x00000CC8
	adds r0, r6, r3
	str r1, [r0]
	ldr r0, _08012C14 @ =0x0000922E
	ldr r1, _08012C18 @ =0x00005BB7
	bl GetFile
	str r0, [r6, #0x20]
	ldr r0, _08012C1C @ =0x03003584
	ldr r2, [r0]
	ldr r0, _08012C20 @ =0x00004C60
	adds r1, r2, r0
	ldr r3, _08012C24 @ =0x00004CA0
	adds r2, r2, r3
	ldr r3, _08012C28 @ =0x00000CA8
	adds r0, r6, r3
	movs r3, #6
	str r3, [sp]
	movs r3, #0x40
	bl rgb555_08237468
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_08012BE2:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_080117d8
	adds r4, #1
	adds r5, #0xc8
	cmp r4, #0xf
	ble _08012BE2
	ldr r1, _08012C2C @ =0x00000CD4
	adds r0, r6, r1
	adds r1, r7, #0
	movs r2, #0xa
	bl FUN_080223f4
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08012C0C: .4byte 0x00000CA6
_08012C10: .4byte 0x00000CC8
_08012C14: .4byte 0x0000922E
_08012C18: .4byte 0x00005BB7
_08012C1C: .4byte 0x03003584
_08012C20: .4byte 0x00004C60
_08012C24: .4byte 0x00004CA0
_08012C28: .4byte 0x00000CA8
_08012C2C: .4byte 0x00000CD4
