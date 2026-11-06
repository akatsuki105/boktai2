	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	movs r0, #0xa
	strh r0, [r6, #0x1c]
	strh r0, [r6, #0x1e]
	adds r5, r6, #0
	adds r5, #0x24
	ldr r1, _0805B78C @ =0x0000210E
	adds r0, r5, #0
	bl Video_GetAuxSprite
	str r4, [r6, #0x20]
	movs r1, #0x32
	cmp r4, #0
	bne _0805B766
	movs r1, #0x2c
_0805B766:
	adds r0, r5, #0
	bl Video_SetAuxSpritePltt
	adds r5, r6, #0
	adds r5, #0x40
	movs r4, #0
_0805B772:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Entity0805b790_InitElem
	adds r4, #1
	adds r5, #0x8c
	cmp r4, #0xf
	ble _0805B772
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805B78C: .4byte 0x0000210E
