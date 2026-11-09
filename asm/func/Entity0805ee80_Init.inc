	push {r4, r5, r6, lr}
	adds r6, r0, #0
	str r1, [r6, #0x50]
	adds r5, r6, #0
	adds r5, #0x18
	movs r4, #1
_0805EE28:
	adds r0, r5, #0
	ldr r1, _0805EE7C @ =0x00005AFD
	bl Video_GetAuxSprite
	adds r5, #0x1c
	subs r4, #1
	cmp r4, #0
	bge _0805EE28
	adds r0, r6, #0
	adds r0, #0x18
	movs r1, #9
	bl Video_SetAuxSpritePltt
	adds r0, r6, #0
	adds r0, #0x34
	movs r1, #0xa
	bl Video_SetAuxSpritePltt
	adds r5, r6, #0
	adds r5, #0x54
	movs r4, #0
_0805EE52:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Entity0805ee80_InitElem
	adds r4, #1
	adds r5, #0x4c
	cmp r4, #7
	ble _0805EE52
	ldr r0, [r6, #0x50]
	bl Entity0805f2dc_Create
	movs r2, #0xad
	lsls r2, r2, #2
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805EE7C: .4byte 0x00005AFD
