	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	cmp r0, #0
	beq _08050256
	movs r0, #0
	strb r0, [r1]
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x62
	bls _0805023C
	movs r0, #0x63
	strh r0, [r4, #0x1e]
_0805023C:
	ldrh r0, [r4, #0x1e]
	cmp r0, #0xb
	bne _08050246
	bl FUN_0803cc70
_08050246:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0804fb04
	adds r0, r4, #0
	movs r1, #3
	bl FUN_0804fbd0
_08050256:
	ldrh r0, [r4, #0x1e]
	cmp r0, #0xb
	bne _08050268
	ldr r0, [r4, #0x24]
	cmp r0, #0x14
	bne _08050268
	movs r0, #4
	bl Sound_FadeOutBGM
_08050268:
	ldr r0, [r4, #0x24]
	cmp r0, #0x59
	bls _0805029C
	movs r1, #5
	adds r0, r4, #0
	adds r0, #0x28
	movs r2, #0
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x29
	movs r0, #1
	strb r0, [r1]
	str r2, [r4, #0x24]
	ldr r2, _08050298 @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r4, #0
	bl FUN_0804fbe0
	b _080502A0
	.align 2, 0
_08050298: .4byte 0x030044BC
_0805029C:
	adds r0, #1
	str r0, [r4, #0x24]
_080502A0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
