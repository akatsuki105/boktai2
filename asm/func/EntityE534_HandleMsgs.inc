	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _08012024 @ =0x00000CD4
	adds r6, r5, r0
	movs r7, #0
	ldr r0, _08012028 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	ldr r2, _0801202C @ =0x00000CDA
	adds r0, r5, r2
	b _080120BA
	.align 2, 0
_08012024: .4byte 0x00000CD4
_08012028: .4byte 0x03002B4C
_0801202C: .4byte 0x00000CDA
_08012030:
	ldr r0, _08012060 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r6, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl EntityMsgBox_BeginWait
	ldrb r0, [r4, #6]
	cmp r0, #1
	beq _08012080
	cmp r0, #1
	bgt _08012064
	cmp r0, #0
	beq _0801206A
	b _080120B0
	.align 2, 0
_08012060: .4byte 0x03002B4C
_08012064:
	cmp r0, #2
	beq _0801209C
	b _080120B0
_0801206A:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl EntityE534_HandleCmd0
	ldr r1, _0801207C @ =0x00000CD4
	adds r0, r5, r1
	b _0801208E
	.align 2, 0
_0801207C: .4byte 0x00000CD4
_08012080:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl EntityE534_HandleCmd1
	ldr r2, _08012098 @ =0x00000CD4
	adds r0, r5, r2
_0801208E:
	movs r1, #1
	bl EntityMsgBox_EndWait
	b _080120B0
	.align 2, 0
_08012098: .4byte 0x00000CD4
_0801209C:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl EntityE534_HandleCmd2
	ldr r1, _080120CC @ =0x00000CD4
	adds r0, r5, r1
	movs r1, #1
	bl EntityMsgBox_EndWait
_080120B0:
	adds r7, #1
	ldr r0, _080120D0 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r6, #6
_080120BA:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r7, r0
	blt _08012030
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080120CC: .4byte 0x00000CD4
_080120D0: .4byte 0x03002B4C
