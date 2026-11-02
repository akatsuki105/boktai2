	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r7, r6, r0
	adds r0, #4
	adds r4, r6, r0
_081EA0A8:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081EA0B8
	movs r0, #1
	b _081EA0BA
_081EA0B8:
	movs r0, #0
_081EA0BA:
	cmp r0, #0
	beq _081EA0CE
	movs r1, #0xb
	ldrsb r1, [r4, r1]
	movs r0, #0x2c
	muls r0, r1, r0
	adds r0, #0x1c
	adds r0, r6, r0
	bl AuxSprite_Remove
_081EA0CE:
	adds r4, #0xc
	adds r5, #1
	cmp r5, #7
	ble _081EA0A8
	movs r1, #0
	ldr r0, _081EA0E4 @ =0x030001B8
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EA0E4: .4byte 0x030001B8
