	push {r4, r5, r6, lr}
	sub sp, #0x24
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x78
	movs r0, #9
	movs r1, #5
	movs r2, #0x10
	movs r3, #2
	bl FUN_0821b28c
	bl FUN_0823cd38
	adds r2, r0, #0
	movs r0, #9
	movs r1, #5
	bl Video_DrawText
	movs r1, #0x20
	ldr r0, [r6, #0x44]
	ands r0, r1
	cmp r0, #0
	beq _08213BEA
	movs r0, #3
	movs r1, #8
	movs r2, #0x18
	movs r3, #4
	bl FUN_0821b28c
	ldr r1, _08213BBC @ =0x00001650
	adds r0, r6, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #7
	bl Textbox_LookupString
	adds r2, r0, #0
	movs r0, #4
	movs r1, #8
	bl Video_DrawText
	movs r0, #0
	str r0, [sp, #0x20]
	add r0, sp, #0x20
	ldr r2, _08213BC0 @ =0x05000008
	mov r1, sp
	bl CpuSet
	ldr r2, _08213BC4 @ =0x00001654
	adds r0, r6, r2
	ldr r0, [r0]
	bl VM_ParseStringRef
	ldr r1, _08213BC8 @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0xe
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	bl Textbox_LookupString
	adds r2, r0, #0
	mov r1, sp
	movs r0, #0x80
	strb r0, [r1]
	movs r0, #0xb9
	strb r0, [r1, #1]
	adds r1, #2
	b _08213BD2
	.align 2, 0
_08213BBC: .4byte 0x00001650
_08213BC0: .4byte 0x05000008
_08213BC4: .4byte 0x00001654
_08213BC8: .4byte 0x030046A0
_08213BCC:
	strb r0, [r1]
	adds r2, #1
	adds r1, #1
_08213BD2:
	ldrb r0, [r2]
	cmp r0, #0
	bne _08213BCC
	movs r0, #0x80
	strb r0, [r1]
	movs r0, #0xba
	strb r0, [r1, #1]
	movs r0, #3
	movs r1, #0xa
	mov r2, sp
	bl Video_DrawText
_08213BEA:
	adds r0, r5, #0
	adds r0, #0x8e
	movs r4, #0
	strh r4, [r0]
	subs r0, #0x6e
	adds r1, r5, #0
	movs r2, #0x94
	movs r3, #1
	bl Sprite_SetSprite
	adds r1, r5, #0
	adds r1, #0x40
	ldr r0, _08213C20 @ =0x0000FFE0
	strh r0, [r1]
	adds r1, #2
	adds r0, #8
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_0821397c
	adds r0, r5, #0
	adds r0, #0x90
	str r4, [r0]
	add sp, #0x24
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08213C20: .4byte 0x0000FFE0
