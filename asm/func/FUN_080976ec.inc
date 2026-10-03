	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08097724 @ =0x000009EE
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _08097700
	ldr r0, _08097728 @ =0x0000038A
	bl PlaySound_082406e0
_08097700:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _08097734
	ldr r1, _0809772C @ =0x000020C4
	adds r0, r4, r1
	ldr r2, _08097730 @ =0x00003B68
	adds r1, r4, r2
	ldrh r3, [r5]
	movs r2, #0xc
	subs r2, r2, r3
	bl FUN_0808ba20
	b _08097786
	.align 2, 0
_08097724: .4byte 0x000009EE
_08097728: .4byte 0x0000038A
_0809772C: .4byte 0x000020C4
_08097730: .4byte 0x00003B68
_08097734:
	ldr r3, _0809778C @ =0x000020AC
	adds r2, r4, r3
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r0, _08097790 @ =0x00000111
	bl PlaySound_082406e0
	ldr r2, _08097794 @ =0x030046A0
	ldr r0, [r2]
	adds r0, #0x5c
	ldr r3, _08097798 @ =0x00003AEE
	adds r1, r4, r3
	ldrb r1, [r1]
	strh r1, [r0]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	ldr r1, [r2]
	adds r1, #0x5c
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldr r3, _0809779C @ =0x00003FE0
	adds r1, r4, r3
	adds r1, r1, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	lsls r1, r1, #3
	ldr r2, _080977A0 @ =0x08DAA7B0
	adds r1, r1, r2
	bl Player_EquipArmor
	adds r0, r4, #0
	bl FUN_0808bac4
	adds r0, r4, #0
	bl FUN_08096fa8
_08097786:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809778C: .4byte 0x000020AC
_08097790: .4byte 0x00000111
_08097794: .4byte 0x030046A0
_08097798: .4byte 0x00003AEE
_0809779C: .4byte 0x00003FE0
_080977A0: .4byte 0x08DAA7B0
