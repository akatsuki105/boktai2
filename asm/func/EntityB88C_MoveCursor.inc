	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _0804ABBC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0804ABC0
	adds r4, r7, #0
	adds r4, #0x2a
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	movs r0, #0xdc
	bl PlaySound_082406e0
	adds r6, r4, #0
	b _0804ABD8
	.align 2, 0
_0804ABBC: .4byte 0x030044E0
_0804ABC0:
	movs r0, #0x80
	ands r0, r1
	adds r6, r7, #0
	adds r6, #0x2a
	cmp r0, #0
	beq _0804ABD8
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	movs r0, #0xdc
	bl PlaySound_082406e0
_0804ABD8:
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r0, #0
	bge _0804ABEE
	adds r1, r7, #0
	adds r1, #0x2c
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r6]
	mov r8, r1
	b _0804AC02
_0804ABEE:
	movs r1, #0
	ldrsb r1, [r6, r1]
	adds r0, r7, #0
	adds r0, #0x2c
	mov r8, r0
	ldrb r0, [r0]
	cmp r1, r0
	blt _0804AC02
	movs r0, #0
	strb r0, [r6]
_0804AC02:
	adds r0, r7, #0
	adds r0, #0x2b
	movs r2, #0
	ldrsb r2, [r0, r2]
	movs r1, #0
	ldrsb r1, [r6, r1]
	mov sb, r0
	cmp r2, r1
	beq _0804AC6A
	adds r5, r7, #0
	adds r5, #0x58
	movs r4, #0
	mov r1, r8
	ldrb r1, [r1]
	cmp r4, r1
	bge _0804AC4E
_0804AC22:
	lsls r1, r4, #1
	adds r2, r1, #0
	adds r2, #0x1a
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r4, r0
	beq _0804AC32
	adds r2, #1
_0804AC32:
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r3, #0
	bl MainSprite_SetPose
	adds r4, #1
	adds r5, #0x60
	mov r2, r8
	ldrb r2, [r2]
	cmp r4, r2
	blt _0804AC22
_0804AC4E:
	movs r4, #0
	ldrsb r4, [r6, r4]
	movs r1, #0xa0
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	adds r4, #1
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
_0804AC6A:
	ldrb r0, [r6]
	mov r2, sb
	strb r0, [r2]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
