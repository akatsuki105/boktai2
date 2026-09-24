	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r0, _081D1684 @ =0x0000097C
	adds r7, r6, r0
_081D1672:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D1688
	movs r0, #1
	b _081D168A
	.align 2, 0
_081D1684: .4byte 0x0000097C
_081D1688:
	movs r0, #0
_081D168A:
	cmp r0, #0
	beq _081D16A6
	movs r0, #0xc8
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x1c
	adds r4, r6, r4
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x60
	adds r0, r4, #0
	bl Hitbox_Unregister
_081D16A6:
	adds r5, #1
	cmp r5, #0xb
	ble _081D1672
	ldr r1, _081D16B8 @ =0x0300018C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D16B8: .4byte 0x0300018C
