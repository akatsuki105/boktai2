	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x3c
	ldr r1, [r4, #0x64]
	bl LinkShopMsg_TryRecv
	cmp r0, #0
	beq _081E1D96
	cmp r0, #0
	ble _081E1E24
	cmp r0, #1
	beq _081E1D9E
	b _081E1E24
_081E1D96:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r4, #0x50]
	b _081E1E24
_081E1D9E:
	ldrh r0, [r4, #0x3c]
	adds r1, r0, #0
	cmp r1, #6
	bne _081E1DAA
	movs r0, #1
	b _081E1DAC
_081E1DAA:
	movs r0, #0
_081E1DAC:
	cmp r0, #0
	beq _081E1DB4
	movs r0, #0x82
	b _081E1DF8
_081E1DB4:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bne _081E1DC0
	movs r0, #1
	b _081E1DC2
_081E1DC0:
	movs r0, #0
_081E1DC2:
	cmp r0, #0
	beq _081E1DCC
	movs r0, #0x81
	lsls r0, r0, #1
	b _081E1DF8
_081E1DCC:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bne _081E1DD8
	movs r0, #1
	b _081E1DDA
_081E1DD8:
	movs r0, #0
_081E1DDA:
	cmp r0, #0
	beq _081E1DE8
	ldr r0, _081E1DE4 @ =0x00000202
	b _081E1DF8
	.align 2, 0
_081E1DE4: .4byte 0x00000202
_081E1DE8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xa
	bne _081E1DF4
	movs r0, #1
	b _081E1DF6
_081E1DF4:
	movs r0, #0
_081E1DF6:
	movs r0, #2
_081E1DF8:
	ldr r1, [r4, #0x64]
	orrs r1, r0
	str r1, [r4, #0x64]
	ldr r2, _081E1E20 @ =LinkShopManager_StateHandleMsg
	movs r0, #0x80
	lsls r0, r0, #5
	ands r1, r0
	str r2, [r4, #0x4c]
	adds r1, r4, #0
	adds r1, #0x69
	movs r0, #1
	strb r0, [r1]
	adds r1, #1
	movs r0, #4
	strb r0, [r1]
	subs r0, #5
	str r0, [r4, #0x50]
	movs r0, #1
	b _081E1E26
	.align 2, 0
_081E1E20: .4byte LinkShopManager_StateHandleMsg
_081E1E24:
	movs r0, #0
_081E1E26:
	pop {r4}
	pop {r1}
	bx r1
