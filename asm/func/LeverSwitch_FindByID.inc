	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081D0F18 @ =0x0300018C
	ldr r1, [r0]
	cmp r1, #0
	bne _081D0F20
	b _081D0F5A
	.align 2, 0
_081D0F18: .4byte 0x0300018C
_081D0F1C:
	adds r0, r1, #0
	b _081D0F5C
_081D0F20:
	movs r3, #0
	ldr r2, _081D0F40 @ =0x0000097C
	adds r0, r1, r2
	ldr r4, [r0]
	movs r6, #1
	adds r2, r1, #0
	adds r2, #0xda
	adds r1, #0x1c
_081D0F30:
	adds r0, r6, #0
	lsls r0, r3
	ands r0, r4
	cmp r0, #0
	beq _081D0F44
	movs r0, #1
	b _081D0F46
	.align 2, 0
_081D0F40: .4byte 0x0000097C
_081D0F44:
	movs r0, #0
_081D0F46:
	cmp r0, #0
	beq _081D0F50
	ldrh r0, [r2]
	cmp r0, r5
	beq _081D0F1C
_081D0F50:
	adds r2, #0xc8
	adds r1, #0xc8
	adds r3, #1
	cmp r3, #0xb
	ble _081D0F30
_081D0F5A:
	movs r0, #0
_081D0F5C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
