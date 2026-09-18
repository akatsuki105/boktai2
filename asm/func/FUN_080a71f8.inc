	push {lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3f
	ble _080A7224
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080A7228 @ =0x00000341
	adds r1, r2, r0
	movs r0, #5
	strb r0, [r1]
	ldr r0, _080A722C @ =0x00000346
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
_080A7224:
	pop {r0}
	bx r0
	.align 2, 0
_080A7228: .4byte 0x00000341
_080A722C: .4byte 0x00000346
