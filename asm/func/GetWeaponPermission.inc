	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r1, #0
	movs r6, #0
	adds r0, r5, #0
	bl GetWeaponKind
	mov sl, r0
	cmp r0, #3
	beq _08095782
	adds r0, r5, #0
	bl GetWeaponID
	adds r4, r0, #0
	cmp r4, #0x3a
	beq _08095782
	cmp r4, #0x3e
	bne _08095786
_08095782:
	movs r0, #0
	b _08095812
_08095786:
	movs r0, #1
	mov ip, r0
	ldr r1, _080957A4 @ =0x08DA9E68
	lsls r2, r4, #3
	adds r0, r2, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #0xa]
	mov sb, r1
	mov r8, r2
	cmp r0, #0
	bne _080957AC
	ldr r2, _080957A8 @ =0x030046A0
	b _080957D4
	.align 2, 0
_080957A4: .4byte 0x08DA9E68
_080957A8: .4byte 0x030046A0
_080957AC:
	ldr r2, _080957F4 @ =0x030046A0
	ldr r0, [r2]
	adds r1, r0, #0
	adds r1, #0x60
	movs r3, #3
_080957B6:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r5
	bne _080957C2
	movs r0, #0
	mov ip, r0
_080957C2:
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _080957B6
	mov r7, ip
	cmp r7, #0
	beq _080957D4
	movs r0, #0x10
	orrs r6, r0
_080957D4:
	ldr r0, [r2]
	adds r0, #0x40
	movs r2, #0
	ldrsh r1, [r0, r2]
	mov r7, r8
	adds r0, r7, r4
	lsls r0, r0, #2
	add r0, sb
	ldrb r0, [r0, #3]
	cmp r1, r0
	blt _08095810
	mov r0, sl
	cmp r0, #0
	bne _080957F8
	movs r0, #1
	b _0809580E
	.align 2, 0
_080957F4: .4byte 0x030046A0
_080957F8:
	mov r2, sl
	cmp r2, #1
	bne _08095802
	movs r0, #2
	b _0809580E
_08095802:
	mov r7, sl
	cmp r7, #2
	bne _0809580C
	movs r0, #4
	b _0809580E
_0809580C:
	movs r0, #8
_0809580E:
	orrs r6, r0
_08095810:
	adds r0, r6, #0
_08095812:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
