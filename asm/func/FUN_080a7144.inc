	push {lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r0, _080A7178 @ =0x0000033E
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #0x1e
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x7e
	ble _080A7172
	movs r0, #0x7f
	strh r0, [r1]
	ldr r0, _080A717C @ =0x00000341
	adds r1, r2, r0
	movs r0, #2
	strb r0, [r1]
_080A7172:
	pop {r0}
	bx r0
	.align 2, 0
_080A7178: .4byte 0x0000033E
_080A717C: .4byte 0x00000341
