	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080CB620
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080CB618 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080CB61C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080CB62A
	.align 2, 0
_080CB618: .4byte 0xFFFF0000
_080CB61C: .4byte 0x0000FFFF
_080CB620:
	ldr r1, _080CB658 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080CB62A:
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CB652
	cmp r1, #0
	blt _080CB652
	ldr r0, _080CB65C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CB652
	ldr r0, _080CB660 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CB664
_080CB652:
	movs r4, #0
	b _080CB672
	.align 2, 0
_080CB658: .4byte 0xFFFF0000
_080CB65C: .4byte 0x030046A8
_080CB660: .4byte 0x030046AC
_080CB664:
	ldr r0, _080CB684 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CB672:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080CB688
	adds r0, #4
	b _080CB694
	.align 2, 0
_080CB684: .4byte 0x030046A4
_080CB688:
	ldr r0, _080CB6A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CB694:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CB6AC
	cmp r2, #2
	beq _080CB6B0
	b _080CB6B4
	.align 2, 0
_080CB6A8: .4byte 0x030046A4
_080CB6AC:
	ldrb r0, [r5, #4]
	b _080CB6B2
_080CB6B0:
	ldrb r0, [r5]
_080CB6B2:
	subs r1, r1, r0
_080CB6B4:
	add r0, sp, #8
	strh r1, [r0, #2]
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x18]
	movs r2, #7
	str r2, [sp]
	str r6, [sp, #4]
	add r2, sp, #8
	movs r3, #0
	bl Mover_Init
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
