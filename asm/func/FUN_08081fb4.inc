	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08081FCE
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08080e0c
_08081FCE:
	adds r0, r4, #0
	movs r1, #0x10
	bl PlayerLink_SetFlag35a
	movs r2, #0x82
	lsls r2, r2, #2
	adds r3, r4, r2
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #0x2c
	ldrsh r6, [r4, r2]
	subs r2, r0, r6
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x30
	ldrsh r5, [r4, r1]
	subs r1, r0, r5
	movs r7, #0xc
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	cmp r0, #0x90
	bgt _08082074
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r4, #0x2c]
	str r1, [r4, #0x30]
	ldr r1, _08082038 @ =0x00000471
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _08082040
	movs r0, #8
	subs r0, r0, r1
	subs r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0808203C @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0808204C
	.align 2, 0
_08082038: .4byte 0x00000471
_0808203C: .4byte 0x000002E7
_08082040:
	ldr r2, _0808206C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08082070 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0808204C:
	strb r0, [r1]
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r1, #0x8e
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08080e0c
	b _08082118
	.align 2, 0
_0808206C: .4byte 0x000002E6
_08082070: .4byte 0x000002E7
_08082074:
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r2, r0, r6
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r1, r0, r5
	adds r0, r2, #0
	bl ArcTan2_8
	adds r5, r0, #0
	ldr r2, _080820B0 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080820B4
	asrs r0, r0, #0xc
	b _080820BA
	.align 2, 0
_080820B0: .4byte 0x085B0A08
_080820B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080820BA:
	strh r0, [r4, #0x34]
	ldr r0, _080820D4 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080820D8
	asrs r0, r0, #0xc
	b _080820DE
	.align 2, 0
_080820D4: .4byte 0x085B0A08
_080820D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080820DE:
	strh r0, [r4, #0x38]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08235fd8
	cmp r0, #0
	beq _0808210E
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl LinkPlayer_SetAnimFacing
_0808210E:
	ldr r1, _08082120 @ =0x000001A3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
_08082118:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08082120: .4byte 0x000001A3
