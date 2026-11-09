	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r2, [sp]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081787D6
	b _081788FE
_081787D6:
	movs r0, #0
	mov sl, r0
	ldr r0, _08178808 @ =0x00001012
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _081787E8
	b _081788FE
_081787E8:
	ldr r7, _0817880C @ =0x00000676
	add r7, sb
	ldr r6, _08178810 @ =0x00000674
	add r6, sb
	ldr r2, _08178814 @ =0x00000755
	add r2, sb
	mov r8, r2
_081787F6:
	movs r1, #2
	mov r3, r8
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _08178818
	movs r0, #1
	b _0817881A
	.align 2, 0
_08178808: .4byte 0x00001012
_0817880C: .4byte 0x00000676
_08178810: .4byte 0x00000674
_08178814: .4byte 0x00000755
_08178818:
	movs r0, #0
_0817881A:
	cmp r0, #0
	beq _081788E2
	movs r1, #1
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0817882E
	movs r0, #1
	b _08178830
_0817882E:
	movs r0, #0
_08178830:
	cmp r0, #0
	bne _081788E2
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08178858
	cmp r1, #0
	blt _08178858
	ldr r0, _0817885C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08178858
	ldr r0, _08178860 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08178864
_08178858:
	movs r4, #0
	b _08178872
	.align 2, 0
_0817885C: .4byte 0x030046A8
_08178860: .4byte 0x030046AC
_08178864:
	ldr r0, _08178884 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08178872:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08178888
	adds r0, #4
	b _08178894
	.align 2, 0
_08178884: .4byte 0x030046A4
_08178888:
	ldr r0, _081788A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08178894:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081788AC
	cmp r2, #2
	beq _081788B0
	b _081788B4
	.align 2, 0
_081788A8: .4byte 0x030046A4
_081788AC:
	ldrb r0, [r5, #4]
	b _081788B2
_081788B0:
	ldrb r0, [r5]
_081788B2:
	subs r1, r1, r0
_081788B4:
	movs r3, #2
	ldrsh r0, [r6, r3]
	cmp r0, r1
	beq _081788E2
	cmp r0, r1
	bge _081788D4
	subs r0, r1, r0
	cmp r0, #0
	bge _081788C8
	rsbs r0, r0, #0
_081788C8:
	cmp r0, #0xff
	ble _081788E0
	ldr r1, [sp]
	ldrh r0, [r1, #0xa]
	strh r0, [r7]
	b _081788E2
_081788D4:
	subs r0, r1, r0
	movs r1, #0xa
	bl Div
	ldrh r1, [r7]
	adds r1, r1, r0
_081788E0:
	strh r1, [r7]
_081788E2:
	movs r2, #0x92
	lsls r2, r2, #1
	adds r7, r7, r2
	adds r6, r6, r2
	add r8, r2
	movs r3, #1
	add sl, r3
	ldr r0, _08178910 @ =0x00001012
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	bge _081788FE
	b _081787F6
_081788FE:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08178910: .4byte 0x00001012
