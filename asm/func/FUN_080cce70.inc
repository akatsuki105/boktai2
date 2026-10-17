	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080CCEC4 @ =0x000006AC
	adds r4, r6, r0
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r5, r6, r1
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _080CCED4
	ldr r1, _080CCEC8 @ =0x00002110
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x43
	bl AuxSprite_Add
	movs r0, #4
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	movs r1, #0x32
	bl Video_SetAuxSpritePltt
	movs r0, #1
	strb r0, [r4, #7]
	movs r0, #0x7f
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldr r0, _080CCECC @ =0x00000714
	adds r1, r6, r0
	ldr r0, _080CCED0 @ =FUN_080cca80
	b _080CCF02
	.align 2, 0
_080CCEC4: .4byte 0x000006AC
_080CCEC8: .4byte 0x00002110
_080CCECC: .4byte 0x00000714
_080CCED0: .4byte FUN_080cca80
_080CCED4:
	ldr r1, _080CCF14 @ =0x00008F5D
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl AuxSprite_Add
	adds r0, r5, #0
	movs r1, #0x1d
	bl Video_SetAuxSpritePltt
	ldr r0, _080CCF18 @ =0x0000922E
	ldr r1, _080CCF1C @ =0x00000837
	bl GetFile
	ldr r2, _080CCF20 @ =0x00000704
	adds r1, r6, r2
	str r0, [r1]
	ldr r0, _080CCF24 @ =0x00000714
	adds r1, r6, r0
	ldr r0, _080CCF28 @ =FUN_080cc944
_080CCF02:
	str r0, [r1]
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CCF14: .4byte 0x00008F5D
_080CCF18: .4byte 0x0000922E
_080CCF1C: .4byte 0x00000837
_080CCF20: .4byte 0x00000704
_080CCF24: .4byte 0x00000714
_080CCF28: .4byte FUN_080cc944
