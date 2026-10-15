	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080A1740 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A1744 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r5, [r0, r2]
	cmp r5, #0
	bne _080A174C
	ldrh r0, [r4, #0x1e]
	cmp r0, #1
	bne _080A1738
	ldr r0, _080A1748 @ =0x00000237
	bl sound_08240740
	strh r5, [r4, #0x1e]
_080A1738:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x46
	b _080A17FC
	.align 2, 0
_080A1740: .4byte 0x030046A0
_080A1744: .4byte 0x00000942
_080A1748: .4byte 0x00000237
_080A174C:
	adds r0, r4, #0
	bl FUN_080a16b0
	adds r5, r0, #0
	cmp r5, #0
	beq _080A17E8
	ldrh r0, [r4, #0x1e]
	cmp r0, #0
	bne _080A1778
	ldr r0, _080A17A4 @ =0x00000237
	bl PlaySound_082406e0
	movs r0, #1
	strh r0, [r4, #0x1e]
	adds r0, r4, #0
	adds r0, #0xf4
	ldr r0, [r0]
	cmp r0, #0
	beq _080A1778
	movs r1, #0
	bl VM_ExecByID
_080A1778:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x45
	bl Video_SetAuxSpritePltt
	adds r3, r4, #0
	adds r3, #0xac
	ldr r2, [r3]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r3]
	ldrh r0, [r4, #0x1a]
	lsrs r0, r0, #1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A17A8
	movs r0, #4
	orrs r2, r0
	b _080A17AE
	.align 2, 0
_080A17A4: .4byte 0x00000237
_080A17A8:
	movs r0, #5
	rsbs r0, r0, #0
	ands r2, r0
_080A17AE:
	str r2, [r3]
	ldrh r1, [r4, #0x1a]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _080A17DC
	adds r0, r4, #0
	adds r0, #0x80
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	adds r1, #0x84
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r3, #0x80
	str r3, [sp]
	ldr r3, _080A17E4 @ =0x0000B546
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
_080A17DC:
	ldrh r0, [r4, #0x1a]
	adds r0, #1
	strh r0, [r4, #0x1a]
	b _080A180E
	.align 2, 0
_080A17E4: .4byte 0x0000B546
_080A17E8:
	ldrh r0, [r4, #0x1e]
	cmp r0, #1
	bne _080A17F6
	ldr r0, _080A1818 @ =0x00000237
	bl sound_08240740
	strh r5, [r4, #0x1e]
_080A17F6:
	adds r0, r4, #0
	adds r0, #0x90
	movs r1, #0x44
_080A17FC:
	bl Video_SetAuxSpritePltt
	adds r2, r4, #0
	adds r2, #0xac
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	strh r5, [r4, #0x1a]
_080A180E:
	movs r0, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A1818: .4byte 0x00000237
