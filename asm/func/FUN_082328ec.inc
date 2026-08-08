	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08232914
	cmp r1, #0
	blt _08232914
	ldr r0, _08232918 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08232914
	ldr r0, _0823291C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08232920
_08232914:
	movs r4, #0
	b _0823292E
	.align 2, 0
_08232918: .4byte 0x030046A8
_0823291C: .4byte 0x030046AC
_08232920:
	ldr r0, _08232940 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0823292E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08232944
	adds r0, #4
	b _08232950
	.align 2, 0
_08232940: .4byte 0x030046A4
_08232944:
	ldr r0, _08232964 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08232950:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08232968
	cmp r2, #2
	beq _0823296C
	b _08232970
	.align 2, 0
_08232964: .4byte 0x030046A4
_08232968:
	ldrb r0, [r5, #4]
	b _0823296E
_0823296C:
	ldrb r0, [r5]
_0823296E:
	subs r1, r1, r0
_08232970:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
