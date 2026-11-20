	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r6, r1, #0
	str r2, [sp, #4]
	adds r7, r6, #0
	adds r7, #0xc4
	ldr r0, _08045EE4 @ =0x00001A2C
	add r0, r8
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	str r0, [sp, #8]
	mov r0, r8
	ldr r3, [r0, #0x18]
	movs r1, #0
	ldrsh r2, [r3, r1]
	movs r4, #0
	ldrsh r0, [r7, r4]
	subs r2, r2, r0
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r4, #4
	ldrsh r0, [r7, r4]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r5, r1, #0
	muls r5, r1, r5
	adds r1, r5, #0
	adds r0, r0, r1
	str r0, [r6, #0x14]
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #0
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r3, r4]
	movs r5, #4
	ldrsh r2, [r7, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r2, r6, #0
	adds r2, #0x65
	ldrb r1, [r2]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	lsls r0, r4, #0x18
	asrs r3, r0, #0x18
	cmp r3, #8
	ble _08045EE8
	adds r0, r1, #0
	adds r0, #8
	b _08045EF8
	.align 2, 0
_08045EE4: .4byte 0x00001A2C
_08045EE8:
	movs r0, #8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08045EF6
	adds r0, r1, #0
	subs r0, #8
	b _08045EF8
_08045EF6:
	adds r0, r1, r4
_08045EF8:
	strb r0, [r2]
	ldrb r4, [r6, #5]
	cmp r4, #0
	beq _08045FAE
	movs r0, #0
	mov sb, r0
	mov r1, sb
	strb r1, [r6, #5]
	ldrb r0, [r6, #7]
	ldr r2, _08045F5C @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r5, r6, #0
	adds r5, #0xa4
	lsls r0, r0, #5
	add r0, r8
	mov ip, r0
	ldr r2, _08045F60 @ =0x0000192C
	add ip, r2
	ldrh r3, [r1]
	adds r2, r6, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r4, r1, #0
	ands r4, r0
	adds r1, r4, #0
	strb r4, [r6, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r2
	cmp r0, #2
	bhi _08045F64
	movs r0, #8
	subs r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x2d
	movs r4, #1
	strb r4, [r0]
	b _08045F72
	.align 2, 0
_08045F5C: .4byte 0x085AB404
_08045F60: .4byte 0x0000192C
_08045F64:
	adds r1, r6, #0
	adds r1, #0x2c
	strb r4, [r1]
	adds r0, r6, #0
	adds r0, #0x2d
	mov r2, sb
	strb r2, [r0]
_08045F72:
	adds r4, r0, #0
	ldrb r0, [r1]
	adds r0, r0, r3
	strh r0, [r6, #0x2e]
	ldrh r2, [r6, #0x2e]
	movs r3, #1
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	mov r1, ip
	bl MainSprite_SetAnim
	ldrb r1, [r4]
	cmp r1, #0
	beq _08045F98
	ldr r1, [r5, #8]
	movs r2, #4
	orrs r1, r2
	b _08045FA0
_08045F98:
	ldr r1, [r5, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08045FA0:
	str r1, [r5, #8]
	movs r1, #1
	strb r1, [r6, #8]
	mov r3, sl
	ldrb r1, [r3]
	strb r1, [r6, #0xb]
	b _08046046
_08045FAE:
	ldrb r0, [r6, #7]
	ldr r2, _08046004 @ =0x085AB404
	lsls r1, r0, #1
	adds r1, r1, r2
	adds r5, r6, #0
	adds r5, #0xa4
	lsls r0, r0, #5
	add r0, r8
	mov ip, r0
	ldr r0, _08046008 @ =0x0000192C
	add ip, r0
	ldrh r1, [r1]
	mov sb, r1
	adds r2, r6, #0
	adds r2, #0x65
	ldrb r0, [r2]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	adds r3, r1, #0
	ands r3, r0
	adds r1, r3, #0
	strb r3, [r6, #0x19]
	subs r0, r1, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r2
	cmp r0, #2
	bhi _0804600C
	movs r0, #8
	subs r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x2c
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x2d
	movs r2, #1
	strb r2, [r0]
	b _08046018
	.align 2, 0
_08046004: .4byte 0x085AB404
_08046008: .4byte 0x0000192C
_0804600C:
	adds r1, r6, #0
	adds r1, #0x2c
	strb r3, [r1]
	adds r0, r6, #0
	adds r0, #0x2d
	strb r4, [r0]
_08046018:
	adds r4, r0, #0
	ldrb r0, [r1]
	add r0, sb
	strh r0, [r6, #0x2e]
	ldrh r2, [r6, #0x2e]
	movs r3, #1
	str r3, [sp]
	adds r0, r5, #0
	mov r1, ip
	bl MainSprite_SetAnim
	ldrb r1, [r4]
	cmp r1, #0
	beq _0804603C
	ldr r1, [r5, #8]
	movs r2, #4
	orrs r1, r2
	b _08046044
_0804603C:
	ldr r1, [r5, #8]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08046044:
	str r1, [r5, #8]
_08046046:
	mov r3, r8
	ldr r1, [r3, #0x28]
	movs r2, #0xf
	ands r1, r2
	ldr r4, [sp, #4]
	cmp r1, r4
	bne _080460DA
	adds r1, r6, #0
	adds r1, #0x29
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	blt _08046082
	mov r1, r8
	adds r1, #0x25
	ldrb r1, [r1]
	cmp r1, #0
	beq _08046082
	movs r0, #5
	strb r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #5]
	movs r0, #0
	str r0, [r6, #0x10]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r6, #0x1c]
	movs r0, #0
	b _08046244
_08046082:
	ldrb r1, [r6, #0x1f]
	cmp r1, #0
	beq _080460DA
	mov r5, r8
	ldrb r1, [r5, #0x1e]
	cmp r1, #0
	beq _080460DA
	mov r3, r8
	adds r3, #0x20
	adds r4, r6, #0
	adds r4, #0x26
	ldrb r1, [r3]
	ldrb r2, [r4]
	cmp r1, r2
	bne _080460B0
	mov r1, r8
	adds r1, #0x21
	adds r2, r6, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhs _080460CA
_080460B0:
	ldrb r1, [r3]
	subs r1, #1
	ldrb r4, [r4]
	cmp r1, r4
	bne _080460DA
	mov r1, r8
	adds r1, #0x21
	adds r2, r6, #0
	adds r2, #0x27
	ldrb r1, [r1]
	ldrb r2, [r2]
	cmp r1, r2
	bhi _080460DA
_080460CA:
	movs r0, #0
	strb r0, [r6, #0x1e]
	movs r1, #6
	strb r1, [r6, #4]
	movs r1, #1
	strb r1, [r6, #5]
	str r0, [r6, #0x10]
	b _08046244
_080460DA:
	mov r4, r8
	ldr r3, [r4, #0x18]
	ldr r4, [r6, #0x3c]
	movs r5, #0
	ldrsh r2, [r3, r5]
	movs r5, #0
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _080460F0
	rsbs r2, r2, #0
_080460F0:
	cmp r2, r4
	bge _0804611E
	movs r1, #2
	ldrsh r2, [r3, r1]
	movs r5, #2
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _08046104
	rsbs r2, r2, #0
_08046104:
	cmp r2, #0xff
	bgt _0804611E
	movs r1, #4
	ldrsh r2, [r3, r1]
	movs r5, #4
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _08046118
	rsbs r2, r2, #0
_08046118:
	movs r1, #1
	cmp r2, r4
	blt _08046120
_0804611E:
	movs r1, #0
_08046120:
	cmp r1, #0
	beq _08046196
	mov r0, r8
	ldr r1, [r0, #0x18]
	movs r3, #0
	ldrsh r2, [r1, r3]
	mov ip, r2
	movs r4, #0
	ldrsh r0, [r7, r4]
	subs r3, r2, r0
	movs r5, #4
	ldrsh r4, [r1, r5]
	movs r2, #4
	ldrsh r1, [r7, r2]
	subs r2, r4, r1
	adds r5, r3, #0
	muls r5, r3, r5
	mov sb, r5
	adds r3, r2, #0
	muls r3, r2, r3
	adds r2, r3, #0
	add sb, r2
	mov r5, ip
	subs r0, r0, r5
	subs r1, r1, r4
	bl ArcTan2_8
	adds r2, r0, #0
	ldr r1, [sp, #8]
	subs r2, r1, r2
	mov r3, sl
	ldrb r1, [r3]
	adds r1, #0x80
	ldr r4, [sp, #8]
	subs r1, r4, r1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	cmp r2, #0
	bge _08046174
	rsbs r2, r2, #0
_08046174:
	mov r5, r8
	ldr r3, [r5, #0x18]
	cmp r2, #0x3f
	bgt _08046196
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r1, #0
	bge _08046186
	rsbs r1, r1, #0
_08046186:
	cmp r1, #0x1f
	bgt _08046196
	adds r2, r6, #0
	adds r2, #0x37
	movs r1, #1
	strb r1, [r2]
	mov r1, sb
	str r1, [r6, #0x44]
_08046196:
	ldrb r2, [r6, #0xb]
	mov r4, sl
	ldrb r1, [r4]
	subs r1, r2, r1
	cmp r1, #0
	bge _080461A4
	rsbs r1, r1, #0
_080461A4:
	cmp r1, #0x3f
	ble _080461EC
	ldr r1, [r6, #0x40]
	lsrs r4, r1, #1
	movs r5, #0
	ldrsh r2, [r3, r5]
	movs r5, #0
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _080461BC
	rsbs r2, r2, #0
_080461BC:
	cmp r2, r4
	bge _08046234
	movs r1, #2
	ldrsh r2, [r3, r1]
	movs r5, #2
	ldrsh r1, [r7, r5]
	subs r2, r2, r1
	cmp r2, #0
	bge _080461D0
	rsbs r2, r2, #0
_080461D0:
	cmp r2, #0xff
	bgt _08046234
	movs r1, #4
	ldrsh r2, [r3, r1]
	movs r3, #4
	ldrsh r1, [r7, r3]
	subs r2, r2, r1
	cmp r2, #0
	bge _080461E4
	rsbs r2, r2, #0
_080461E4:
	movs r3, #1
	cmp r2, r4
	blt _08046236
	b _08046234
_080461EC:
	adds r4, r3, #0
	ldr r5, [r6, #0x40]
	mov sb, r5
	movs r2, #0
	ldrsh r1, [r4, r2]
	mov r8, r1
	movs r5, #0
	ldrsh r1, [r7, r5]
	mov r5, r8
	subs r2, r5, r1
	cmp r2, #0
	bge _08046206
	rsbs r2, r2, #0
_08046206:
	cmp r2, sb
	bge _08046234
	movs r1, #2
	ldrsh r2, [r4, r1]
	movs r4, #2
	ldrsh r1, [r7, r4]
	subs r2, r2, r1
	cmp r2, #0
	bge _0804621A
	rsbs r2, r2, #0
_0804621A:
	cmp r2, #0xff
	bgt _08046234
	movs r5, #4
	ldrsh r2, [r3, r5]
	movs r3, #4
	ldrsh r1, [r7, r3]
	subs r2, r2, r1
	cmp r2, #0
	bge _0804622E
	rsbs r2, r2, #0
_0804622E:
	movs r3, #1
	cmp r2, sb
	blt _08046236
_08046234:
	movs r3, #0
_08046236:
	cmp r3, #0
	bne _08046244
	ldrb r1, [r6, #0xc]
	strb r1, [r6, #4]
	movs r1, #1
	strb r1, [r6, #5]
	str r3, [r6, #0x10]
_08046244:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
