	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BFC08 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x86
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080BFBC6
	adds r1, r0, #0
	movs r0, #0x80
	bl Div
	adds r1, r0, #0
	cmp r1, #0
	bgt _080BFBC8
_080BFBC6:
	movs r1, #1
_080BFBC8:
	adds r2, r4, #0
	adds r2, #0x68
	ldrh r0, [r2]
	adds r1, r0, r1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _080BFBE0
	adds r0, r1, #0
	subs r0, #0xc
	strh r0, [r2]
_080BFBE0:
	ldrh r0, [r2]
	lsrs r0, r0, #2
	strh r0, [r4, #0x30]
	ldr r1, _080BFC0C @ =0x0000057C
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080BFC3C
	ldr r0, _080BFC08 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _080BFC10 @ =0x0000042E
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, #1
	bhi _080BFC18
	ldr r0, _080BFC14 @ =0x0000023A
	bl PlaySound_082406e0
	b _080BFC3C
	.align 2, 0
_080BFC08: .4byte 0x03002BE0
_080BFC0C: .4byte 0x0000057C
_080BFC10: .4byte 0x0000042E
_080BFC14: .4byte 0x0000023A
_080BFC18:
	cmp r0, #3
	bhi _080BFC28
	ldr r0, _080BFC24 @ =0x0000023B
	bl PlaySound_082406e0
	b _080BFC3C
	.align 2, 0
_080BFC24: .4byte 0x0000023B
_080BFC28:
	cmp r0, #5
	bhi _080BFC36
	movs r0, #0x8f
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080BFC3C
_080BFC36:
	ldr r0, _080BFC58 @ =0x0000023D
	bl PlaySound_082406e0
_080BFC3C:
	ldr r0, _080BFC5C @ =0x0000057C
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080BFC52
	movs r0, #0
	strh r0, [r1]
_080BFC52:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BFC58: .4byte 0x0000023D
_080BFC5C: .4byte 0x0000057C
