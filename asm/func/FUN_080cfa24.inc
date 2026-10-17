	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080CFA38 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CFA3C
	movs r1, #1
	rsbs r1, r1, #0
	b _080CFA40
	.align 2, 0
_080CFA38: .4byte 0x03002C68
_080CFA3C:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080CFA40:
	ldr r0, [r4, #0x18]
	cmp r0, r1
	bne _080CFA4C
	movs r0, #8
	bl FUN_0823bca8
_080CFA4C:
	ldr r0, _080CFA5C @ =0x000003CE
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CFA5C: .4byte 0x000003CE
