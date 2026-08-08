	push {lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r0, _08063D58 @ =0x0000043C
	adds r1, r3, r0
_08063D22:
	ldrh r0, [r1]
	cmp r0, #0
	bne _08063D68
	adds r1, #2
	adds r2, #1
	cmp r2, #2
	ble _08063D22
	ldr r1, _08063D5C @ =0x0000038E
	adds r0, r3, r1
	ldrb r0, [r0]
	ldr r1, _08063D60 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _08063D68
	ldr r1, _08063D64 @ =0x000004C7
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08063D68
	movs r0, #0
	b _08063D6A
	.align 2, 0
_08063D58: .4byte 0x0000043C
_08063D5C: .4byte 0x0000038E
_08063D60: .4byte 0x030046A0
_08063D64: .4byte 0x000004C7
_08063D68:
	movs r0, #0xa
_08063D6A:
	pop {r1}
	bx r1
	.align 2, 0
