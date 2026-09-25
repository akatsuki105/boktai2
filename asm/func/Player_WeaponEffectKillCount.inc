	push {lr}
	movs r0, #0x80
	ldr r1, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _08063E68
	ldr r0, _08063E64 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x8a
	lsls r1, r1, #2
_08063E54:
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x16
	cmp r0, #0xa
	ble _08063ED2
	movs r0, #0xa
	b _08063ED2
	.align 2, 0
_08063E64: .4byte 0x030046A0
_08063E68:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08063E84
	ldr r0, _08063E7C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08063E80 @ =0x0000022A
	b _08063E54
	.align 2, 0
_08063E7C: .4byte 0x030046A0
_08063E80: .4byte 0x0000022A
_08063E84:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08063E9C
	ldr r0, _08063E98 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x8b
	lsls r1, r1, #2
	b _08063E54
	.align 2, 0
_08063E98: .4byte 0x030046A0
_08063E9C:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r1
	cmp r0, #0
	beq _08063EB8
	ldr r0, _08063EB0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08063EB4 @ =0x0000022E
	b _08063E54
	.align 2, 0
_08063EB0: .4byte 0x030046A0
_08063EB4: .4byte 0x0000022E
_08063EB8:
	movs r0, #0x80
	lsls r0, r0, #4
	ands r1, r0
	cmp r1, #0
	beq _08063ED0
	ldr r0, _08063ECC @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x8c
	lsls r1, r1, #2
	b _08063E54
	.align 2, 0
_08063ECC: .4byte 0x030046A0
_08063ED0:
	movs r0, #0
_08063ED2:
	pop {r1}
	bx r1
	.align 2, 0
