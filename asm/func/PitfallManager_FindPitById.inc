	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _081D0B90 @ =0x03000188
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x38
	ldr r0, [r0, #0x68]
	cmp r0, #0
	bne _081D0B98
	b _081D0BCA
	.align 2, 0
_081D0B90: .4byte 0x03000188
_081D0B94:
	adds r0, r1, #0
	b _081D0BCC
_081D0B98:
	movs r3, #0
	movs r6, #1
	adds r4, r0, #0
	adds r2, r1, #0
_081D0BA0:
	adds r0, r6, #0
	lsls r0, r3
	ands r0, r4
	cmp r0, #0
	beq _081D0BAE
	movs r0, #1
	b _081D0BB0
_081D0BAE:
	movs r0, #0
_081D0BB0:
	cmp r0, #0
	beq _081D0BC2
	ldr r1, [r2]
	adds r0, r1, #0
	adds r0, #0x88
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r0, r5
	beq _081D0B94
_081D0BC2:
	adds r2, #4
	adds r3, #1
	cmp r3, #0xb
	ble _081D0BA0
_081D0BCA:
	movs r0, #0
_081D0BCC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
