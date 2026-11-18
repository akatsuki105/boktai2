	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	movs r0, #0xe6
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081A6746
	b _081A6E0E
_081A6746:
	ldr r0, [r4]
	movs r1, #0x20
	movs r2, #0xca
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A675C
	movs r0, #1
	b _081A675E
_081A675C:
	movs r0, #0
_081A675E:
	cmp r0, #0
	beq _081A6764
	b _081A6E0E
_081A6764:
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _081A6774
	b _081A6DF8
_081A6774:
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _081A679C
	ldr r4, _081A6798 @ =0x0000048C
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A678C
	b _081A6DF8
_081A678C:
	movs r1, #0
	strh r2, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x43
	strb r1, [r0]
	b _081A6DF8
	.align 2, 0
_081A6798: .4byte 0x0000048C
_081A679C:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _081A67AC
	b _081A6DF8
_081A67AC:
	movs r4, #1
	mov r0, r8
	ldrh r3, [r0, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _081A67BC
	b _081A6AC8
_081A67BC:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, r8
	ldr r1, [r2, #0x34]
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	bne _081A67CE
	b _081A6DF8
_081A67CE:
	ldr r2, _081A6860 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081A67E2
	b _081A6DF8
_081A67E2:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081A67F0
	b _081A6DF8
_081A67F0:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _081A6808
	b _081A6950
_081A6808:
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _081A6870
	ands r3, r1
	cmp r3, #0
	beq _081A6870
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081A682E
	rsbs r1, r1, #0
_081A682E:
	cmp r1, #0x20
	bgt _081A6870
	mov r3, r8
	ldrh r0, [r3, #0x3c]
	ldr r5, _081A6864 @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _081A6868 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _081A686C @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _081A6DF8
	.align 2, 0
_081A6860: .4byte 0x0000A007
_081A6864: .4byte 0x000004BE
_081A6868: .4byte 0x0000048C
_081A686C: .4byte 0x0000044E
_081A6870:
	movs r1, #0
	strh r1, [r7, #0x3e]
	ldr r5, _081A6898 @ =0x0000048A
	adds r0, r6, r5
	strh r1, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081A68A0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A689C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081A690E
	.align 2, 0
_081A6898: .4byte 0x0000048A
_081A689C: .4byte 0x03002BE0
_081A68A0:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081A68BC
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081A68B8 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081A690E
	.align 2, 0
_081A68B8: .4byte 0x03002BE0
_081A68BC:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081A68D8
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081A68D4 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081A690E
	.align 2, 0
_081A68D4: .4byte 0x03002BE0
_081A68D8:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081A68F4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081A68F0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081A690E
	.align 2, 0
_081A68F0: .4byte 0x03002BE0
_081A68F4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081A6906
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081A690E
_081A6906:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081A6910
_081A690E:
	movs r3, #1
_081A6910:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _081A6944 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _081A6932
	b _081A6A88
_081A6932:
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A6948
	movs r0, #1
	b _081A694A
	.align 2, 0
_081A6944: .4byte 0x0000049C
_081A6948:
	movs r0, #0
_081A694A:
	cmp r0, #0
	bne _081A6A2E
	b _081A6A44
_081A6950:
	strh r2, [r7, #0x3e]
	ldr r1, _081A6978 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, r8
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _081A6980
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A697C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081A69EE
	.align 2, 0
_081A6978: .4byte 0x0000048A
_081A697C: .4byte 0x03002BE0
_081A6980:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081A699C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081A6998 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081A69EE
	.align 2, 0
_081A6998: .4byte 0x03002BE0
_081A699C:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _081A69B8
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081A69B4 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081A69EE
	.align 2, 0
_081A69B4: .4byte 0x03002BE0
_081A69B8:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081A69D4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081A69D0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081A69EE
	.align 2, 0
_081A69D0: .4byte 0x03002BE0
_081A69D4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081A69E6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _081A69EE
_081A69E6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081A69F0
_081A69EE:
	movs r3, #1
_081A69F0:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r5, r8
	ldr r1, [r5, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, sb
	str r4, [r0]
	ldr r5, _081A6A24 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _081A6A88
	movs r1, #2
	subs r2, #0x24
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A6A28
	movs r0, #1
	b _081A6A2A
	.align 2, 0
_081A6A24: .4byte 0x0000049C
_081A6A28:
	movs r0, #0
_081A6A2A:
	cmp r0, #0
	beq _081A6A44
_081A6A2E:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A6A40 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081A6A50
	.align 2, 0
_081A6A40: .4byte 0x03002BE0
_081A6A44:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081A6A88
_081A6A50:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_081A6A88:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081A6AB4
	ldr r5, _081A6AC0 @ =0x0000024E
	adds r2, r6, r5
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _081A6AB4
	strh r1, [r2]
_081A6AB4:
	ldr r5, _081A6AC4 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _081A6DF8
	.align 2, 0
_081A6AC0: .4byte 0x0000024E
_081A6AC4: .4byte 0x0000048C
_081A6AC8:
	ldr r0, _081A6ADC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081A6AE0
	movs r0, #1
	b _081A6AE2
	.align 2, 0
_081A6ADC: .4byte 0x030047A4
_081A6AE0:
	movs r0, #0
_081A6AE2:
	cmp r0, #0
	beq _081A6AF0
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _081A6AF8
_081A6AF0:
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
_081A6AF8:
	mov r0, r8
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _081A6B30 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _081A6B34 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _081A6B26
	cmp r2, #0x17
	bne _081A6B38
_081A6B26:
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	b _081A6B5A
	.align 2, 0
_081A6B30: .4byte 0x0000048C
_081A6B34: .4byte 0x000001DF
_081A6B38:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, r8
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _081A6B26
	mov r0, r8
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _081A6B88 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081A6B5A
	movs r1, #0
_081A6B5A:
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081A6B96
	ldrh r0, [r7, #0x3e]
	lsls r0, r0, #1
	strh r0, [r7, #0x3e]
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	blt _081A6B8C
	asrs r0, r0, #1
	b _081A6B92
	.align 2, 0
_081A6B88: .4byte 0x00000187
_081A6B8C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081A6B92:
	mov r2, sb
	strh r0, [r2]
_081A6B96:
	mov r3, r8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081A6BB4
	mov r0, r8
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _081A6BB0 @ =0x000001DD
	adds r1, r6, r4
	b _081A6C28
	.align 2, 0
_081A6BB0: .4byte 0x000001DD
_081A6BB4:
	mov r4, sp
	mov r3, r8
	adds r3, #0xc
	adds r2, r7, #0
	adds r2, #0xc
	ldrh r0, [r7, #0xc]
	mov r5, r8
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _081A6C14
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081A6C14
	ldr r2, _081A6C04 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A6C08 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081A6C0C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _081A6C10 @ =0x000001DD
	adds r1, r6, r4
	b _081A6C28
	.align 2, 0
_081A6C04: .4byte 0x030046B8
_081A6C08: .4byte 0x000003FF
_081A6C0C: .4byte 0x0203B400
_081A6C10: .4byte 0x000001DD
_081A6C14:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _081A6C48 @ =0x000001DD
	adds r1, r6, r3
_081A6C28:
	strb r0, [r1]
	movs r3, #0
	mov r4, r8
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _081A6C50
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _081A6C4C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _081A6CBE
	.align 2, 0
_081A6C48: .4byte 0x000001DD
_081A6C4C: .4byte 0x03002BE0
_081A6C50:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _081A6C6C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _081A6C68 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _081A6CBE
	.align 2, 0
_081A6C68: .4byte 0x03002BE0
_081A6C6C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _081A6C88
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A6C84 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _081A6CBE
	.align 2, 0
_081A6C84: .4byte 0x03002BE0
_081A6C88:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _081A6CA4
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _081A6CA0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _081A6CBE
	.align 2, 0
_081A6CA0: .4byte 0x03002BE0
_081A6CA4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _081A6CB6
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _081A6CBE
_081A6CB6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081A6CC0
_081A6CBE:
	movs r3, #1
_081A6CC0:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, r8
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _081A6CF4 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _081A6D5C
	movs r1, #2
	ldr r2, _081A6CF8 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A6CFC
	movs r0, #1
	b _081A6CFE
	.align 2, 0
_081A6CF4: .4byte 0x0000049C
_081A6CF8: .4byte 0x00000474
_081A6CFC:
	movs r0, #0
_081A6CFE:
	cmp r0, #0
	beq _081A6D18
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _081A6D14 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081A6D24
	.align 2, 0
_081A6D14: .4byte 0x03002BE0
_081A6D18:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _081A6D5C
_081A6D24:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_081A6D5C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081A6D90
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081A6D90
	ldr r0, _081A6DA8 @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _081A6D90
	strh r1, [r2]
_081A6D90:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _081A6DAC @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _081A6DB0 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A6DB4
	movs r0, #1
	b _081A6DB6
	.align 2, 0
_081A6DA8: .4byte 0x0000024E
_081A6DAC: .4byte 0x030046A0
_081A6DB0: .4byte 0x00000934
_081A6DB4:
	movs r0, #0
_081A6DB6:
	ldr r1, _081A6E20 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _081A6DCE
	movs r0, #0
	strh r0, [r7, #0x3e]
	mov r2, sb
	strh r0, [r2]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #8]
	strb r0, [r3]
_081A6DCE:
	adds r0, r6, #0
	bl Enemy_BurstEmitterParticles
	ldrh r0, [r7, #0x3e]
	strh r0, [r4]
	movs r4, #0xc4
	lsls r4, r4, #1
	adds r1, r6, r4
	mov r5, r8
	ldrh r0, [r5, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081A6DF8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #0x40
	movs r2, #0xca
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
_081A6E0E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A6E20: .4byte 0x0000048A
