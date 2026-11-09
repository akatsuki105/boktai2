	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r5, #0xff
	movs r1, #0
	ldr r2, _0817775C @ =0x00001012
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08177772
	movs r7, #4
	adds r3, r0, #0
	movs r2, #0
	movs r6, #0xcb
	lsls r6, r6, #3
_08177748:
	adds r0, r2, r4
	adds r0, r0, r6
	adds r0, #0xfd
	ldrb r0, [r0]
	ands r0, r7
	cmp r0, #0
	beq _08177760
	movs r0, #1
	b _08177762
	.align 2, 0
_0817775C: .4byte 0x00001012
_08177760:
	movs r0, #0
_08177762:
	cmp r0, #0
	bne _0817778C
	movs r0, #0x92
	lsls r0, r0, #1
	adds r2, r2, r0
	adds r1, #1
	cmp r1, r3
	blt _08177748
_08177772:
	cmp r5, #0xff
	beq _081777C0
	movs r1, #1
	ldr r2, _08177788 @ =0x00001008
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08177790
	movs r0, #1
	b _08177792
	.align 2, 0
_08177788: .4byte 0x00001008
_0817778C:
	adds r5, r1, #0
	b _08177772
_08177790:
	movs r0, #0
_08177792:
	cmp r0, #0
	beq _081777C0
	ldr r0, _081777C8 @ =0x00000FCC
	adds r3, r4, r0
	lsls r2, r5, #3
	adds r2, r2, r5
	lsls r2, r2, #3
	adds r2, r2, r5
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r1, _081777CC @ =0x00000674
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, _081777D0 @ =0x00000FEC
	adds r0, r4, r1
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r2, r2, r1
	adds r2, r4, r2
	str r2, [r0]
_081777C0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081777C8: .4byte 0x00000FCC
_081777CC: .4byte 0x00000674
_081777D0: .4byte 0x00000FEC
