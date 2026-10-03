	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BFF44 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080BFF48 @ =0x0000042E
	adds r0, r0, r1
	ldrh r2, [r0]
	cmp r2, #7
	ble _080BFF2C
	movs r2, #7
_080BFF2C:
	movs r1, #0
	cmp r1, r2
	bge _080BFF56
	movs r4, #1
	movs r3, #2
	movs r6, #0x80
	lsls r6, r6, #1
	adds r0, r5, r6
_080BFF3C:
	cmp r1, #3
	bgt _080BFF4C
	strh r4, [r0, #0x10]
	b _080BFF4E
	.align 2, 0
_080BFF44: .4byte 0x03002BE0
_080BFF48: .4byte 0x0000042E
_080BFF4C:
	strh r3, [r0, #0x10]
_080BFF4E:
	adds r0, #0x2c
	adds r1, #1
	cmp r1, r2
	blt _080BFF3C
_080BFF56:
	cmp r1, #6
	bgt _080BFF72
	movs r2, #0
	movs r0, #0x2c
	muls r0, r1, r0
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r0, r3
	adds r0, r0, r5
_080BFF68:
	strh r2, [r0, #0x10]
	adds r0, #0x2c
	adds r1, #1
	cmp r1, #6
	ble _080BFF68
_080BFF72:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
