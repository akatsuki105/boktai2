	push {r4, r5, r6, lr}
	adds r2, r1, #0
	adds r4, r2, #0
	movs r5, #0
	ldrh r0, [r2, #0x2c]
	cmp r0, #0
	beq _081EE868
	strh r5, [r2, #0x2c]
_081EE868:
	ldr r0, _081EE8B0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081EE8CC
	ldr r0, _081EE8B4 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081EE900
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _081EE900
	ldr r1, _081EE8B8 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081EE8C4
	ldr r3, _081EE8BC @ =0x00000446
	adds r0, r1, r3
	ldrh r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _081EE8AA
	ldr r6, _081EE8C0 @ =0x00000442
	adds r0, r1, r6
	ldrh r0, [r0]
	cmp r0, #4
	bne _081EE8AA
	movs r3, #1
_081EE8AA:
	adds r0, r3, #0
	b _081EE8C6
	.align 2, 0
_081EE8B0: .4byte 0x030047A4
_081EE8B4: .4byte 0x03002C68
_081EE8B8: .4byte 0x03002BE0
_081EE8BC: .4byte 0x00000446
_081EE8C0: .4byte 0x00000442
_081EE8C4:
	movs r0, #0
_081EE8C6:
	cmp r0, #0
	beq _081EE900
	b _081EE904
_081EE8CC:
	ldr r0, _081EE92C @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _081EE8FE
	ldr r0, _081EE930 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #2
	beq _081EE8FE
	ldr r0, _081EE934 @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _081EE8FA
	ldr r0, _081EE938 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _081EE8FA
	movs r1, #1
_081EE8FA:
	cmp r1, #0
	beq _081EE900
_081EE8FE:
	movs r5, #1
_081EE900:
	cmp r5, #0
	beq _081EE954
_081EE904:
	ldrh r1, [r2, #0x28]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _081EE922
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldrh r1, [r2, #0x28]
	movs r0, #1
	orrs r0, r1
	strh r0, [r2, #0x28]
_081EE922:
	ldrh r0, [r2, #0x2e]
	cmp r0, #0
	beq _081EE93C
	subs r0, #1
	b _081EE966
	.align 2, 0
_081EE92C: .4byte 0x03002B48
_081EE930: .4byte 0x030046A0
_081EE934: .4byte 0x03002B8C
_081EE938: .4byte 0x03002B60
_081EE93C:
	ldr r1, [r2]
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _081EE94E
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _081EE950
_081EE94E:
	orrs r1, r3
_081EE950:
	str r1, [r2]
	b _081EE964
_081EE954:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	ldrh r1, [r2, #0x28]
	ldr r0, _081EE970 @ =0x0000FFFE
	ands r0, r1
	strh r0, [r2, #0x28]
_081EE964:
	movs r0, #0x26
_081EE966:
	strh r0, [r2, #0x2e]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081EE970: .4byte 0x0000FFFE
