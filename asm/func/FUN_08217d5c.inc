	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _08217DB8 @ =0x0000166C
	adds r6, r5, r0
	ldr r1, _08217DBC @ =0x00001FDE
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #1
	ldr r3, _08217DC0 @ =0x00000938
	adds r0, r0, r3
	adds r4, r6, r0
	movs r1, #0xbd
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #0x54
	bl Textbox_LookupString
	adds r2, r0, #0
	movs r7, #0
	ldrb r1, [r4]
	cmp r1, #0
	bne _08217D96
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08217DA4
_08217D96:
	ldrb r3, [r2]
	cmp r1, r3
	bne _08217DE4
	ldrb r0, [r4, #1]
	ldrb r2, [r2, #1]
	cmp r0, r2
	bne _08217DE4
_08217DA4:
	ldr r0, _08217DC4 @ =0x00000972
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bne _08217DC8
	movs r7, #1
	b _08217DEA
	.align 2, 0
_08217DB8: .4byte 0x0000166C
_08217DBC: .4byte 0x00001FDE
_08217DC0: .4byte 0x00000938
_08217DC4: .4byte 0x00000972
_08217DC8:
	subs r0, r1, #1
	movs r1, #0
	strh r0, [r2]
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #1
	ldr r2, _08217DE0 @ =0x00000938
	adds r0, r0, r2
	adds r4, r6, r0
	strb r1, [r4]
	strb r1, [r4, #1]
	b _08217DEA
	.align 2, 0
_08217DE0: .4byte 0x00000938
_08217DE4:
	movs r0, #0
	strb r0, [r4]
	strb r0, [r4, #1]
_08217DEA:
	adds r0, r5, #0
	bl FUN_08217bfc
	adds r0, r5, #0
	bl FUN_08217b48
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
