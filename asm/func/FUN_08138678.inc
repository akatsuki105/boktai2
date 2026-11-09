	push {r4, lr}
	adds r4, r0, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08138704
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r3, _081386A4 @ =0x00000544
	adds r2, r4, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081386FC
	cmp r0, #0x3b
	bhi _081386AC
	ldr r0, _081386A8 @ =0x00000482
	adds r1, r4, r0
	movs r0, #2
	b _08138702
	.align 2, 0
_081386A4: .4byte 0x00000544
_081386A8: .4byte 0x00000482
_081386AC:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _081386F0
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _081386F0
	ldr r0, _081386D8 @ =0x00000B54
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081386DC
	subs r0, #1
	strh r0, [r1]
	b _081386F0
	.align 2, 0
_081386D8: .4byte 0x00000B54
_081386DC:
	ldrh r0, [r2]
	movs r1, #0x18
	bl Mod
	cmp r0, #0
	bne _081386F0
	movs r0, #0xf6
	lsls r0, r0, #2
	bl PlaySound_082406e0
_081386F0:
	ldr r3, _081386F8 @ =0x00000482
	adds r1, r4, r3
	movs r0, #3
	b _08138702
	.align 2, 0
_081386F8: .4byte 0x00000482
_081386FC:
	ldr r0, _0813870C @ =0x00000482
	adds r1, r4, r0
	movs r0, #1
_08138702:
	strh r0, [r1]
_08138704:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0813870C: .4byte 0x00000482
