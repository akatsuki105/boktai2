	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ どこで出てくる敵か忘れたのでファイル名は暫定
@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_081a66e0
FUN_081a66e0: @ 0x081A66E0
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081A6714
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081A6714
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _081A671C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081A6714:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A671C: .4byte 0xFEFFFFFF

	thumb_func_start FUN_081a6720
FUN_081a6720: @ 0x081A6720
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
	bl FUN_080e8a60
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
	bl FUN_080e8a60
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
	bl FUN_0823785c
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
	bl FUN_08236640
	b _081A6AF8
_081A6AF0:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08236524
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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
	bl FUN_080e64e4
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

	thumb_func_start FUN_081a6e24
FUN_081a6e24: @ 0x081A6E24
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081A6E40 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A6E44
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A6E46
	.align 2, 0
_081A6E40: .4byte 0x0000046D
_081A6E44:
	movs r0, #0
_081A6E46:
	cmp r0, #0
	beq _081A6F2C
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_081a9774
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _081A6E8C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A6E98
	ldr r1, _081A6E90 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _081A6E94 @ =0x0000046E
	adds r7, r5, r0
	b _081A6F1A
	.align 2, 0
_081A6E8C: .4byte 0x0000025D
_081A6E90: .4byte 0x000004B7
_081A6E94: .4byte 0x0000046E
_081A6E98:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081A6F08 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081A6F0C @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081A6ED2
	ldrb r0, [r7]
	cmp r0, #0
	bne _081A6ED2
	cmp r4, #1
	bne _081A6EC4
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081A6F1E
_081A6EC4:
	cmp r4, #0
	bne _081A6ED2
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081A6F1E
_081A6ED2:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081A6EE4
	movs r3, #6
_081A6EE4:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081A6F10
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081A6F18
	.align 2, 0
_081A6F08: .4byte 0x000004B7
_081A6F0C: .4byte 0x0000046E
_081A6F10:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081A6F18:
	str r0, [r6, #8]
_081A6F1A:
	movs r0, #0
	strb r0, [r7]
_081A6F1E:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_081aa614
	b _081A700E
_081A6F2C:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_081a9774
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _081A6F70 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A6F7C
	ldr r1, _081A6F74 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _081A6F78 @ =0x0000046E
	adds r7, r5, r0
	b _081A6FFE
	.align 2, 0
_081A6F70: .4byte 0x0000025D
_081A6F74: .4byte 0x000004B7
_081A6F78: .4byte 0x0000046E
_081A6F7C:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081A6FEC @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081A6FF0 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081A6FB6
	ldrb r0, [r7]
	cmp r0, #0
	bne _081A6FB6
	cmp r4, #1
	bne _081A6FA8
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081A7002
_081A6FA8:
	cmp r4, #0
	bne _081A6FB6
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081A7002
_081A6FB6:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081A6FC8
	movs r3, #6
_081A6FC8:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081A6FF4
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081A6FFC
	.align 2, 0
_081A6FEC: .4byte 0x000004B7
_081A6FF0: .4byte 0x0000046E
_081A6FF4:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081A6FFC:
	str r0, [r6, #8]
_081A6FFE:
	movs r0, #0
	strb r0, [r7]
_081A7002:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_081aa614
_081A700E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081a701c
FUN_081a701c: @ 0x081A701C
	push {r4, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _081A7034 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A7038
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A703A
	.align 2, 0
_081A7034: .4byte 0x0000046D
_081A7038:
	movs r0, #0
_081A703A:
	cmp r0, #0
	beq _081A7056
	ldrb r0, [r4, #5]
	add r2, sp, #4
	mov r1, sp
	bl FUN_081a9774
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_081aa614
	b _081A706C
_081A7056:
	ldrb r0, [r4, #5]
	add r2, sp, #4
	mov r1, sp
	bl FUN_081a9774
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_081aa614
_081A706C:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081a7074
FUN_081a7074: @ 0x081A7074
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081A70D0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A708C
	movs r0, #0
	strb r0, [r1]
_081A708C:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_081a9774
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _081A70D4 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A70E0
	ldr r1, _081A70D8 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _081A70DC @ =0x0000046E
	adds r7, r5, r0
	b _081A7162
	.align 2, 0
_081A70D0: .4byte 0x0000046D
_081A70D4: .4byte 0x0000025D
_081A70D8: .4byte 0x000004B7
_081A70DC: .4byte 0x0000046E
_081A70E0:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081A7150 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081A7154 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _081A711A
	ldrb r0, [r7]
	cmp r0, #0
	bne _081A711A
	cmp r4, #1
	bne _081A710C
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081A7166
_081A710C:
	cmp r4, #0
	bne _081A711A
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081A7166
_081A711A:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081A712C
	movs r3, #6
_081A712C:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081A7158
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081A7160
	.align 2, 0
_081A7150: .4byte 0x000004B7
_081A7154: .4byte 0x0000046E
_081A7158:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081A7160:
	str r0, [r6, #8]
_081A7162:
	movs r0, #0
	strb r0, [r7]
_081A7166:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081a7174
FUN_081a7174: @ 0x081A7174
	bx lr
	.align 2, 0

	thumb_func_start FUN_081a7178
FUN_081a7178: @ 0x081A7178
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081A7190 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A7194
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A7196
	.align 2, 0
_081A7190: .4byte 0x0000046D
_081A7194:
	movs r0, #0
_081A7196:
	cmp r0, #0
	beq _081A71B8
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080ef86c
	movs r0, #2
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ands r0, r1
	cmp r0, #0
	bne _081A71B8
	movs r0, #1
	orrs r0, r1
	strh r0, [r2]
_081A71B8:
	adds r0, r4, #0
	movs r1, #0x3c
	bl Mod
	cmp r0, #0
	bne _081A71D4
	ldr r2, _081A7220 @ =0x000001DF
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080e5718
_081A71D4:
	ldr r1, _081A7224 @ =0x00000466
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _081A721A
	movs r1, #0x80
	lsls r1, r1, #5
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _081A721A
	ldr r3, _081A7228 @ =FUN_081a7234
	movs r2, #6
	ldr r0, _081A722C @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A7230 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_081A721A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A7220: .4byte 0x000001DF
_081A7224: .4byte 0x00000466
_081A7228: .4byte FUN_081a7234
_081A722C: .4byte 0x0000046D
_081A7230: .4byte 0x0000046B

	thumb_func_start FUN_081a7234
FUN_081a7234: @ 0x081A7234
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _081A724C @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A7250
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A7252
	.align 2, 0
_081A724C: .4byte 0x0000046D
_081A7250:
	movs r0, #0
_081A7252:
	cmp r0, #0
	beq _081A726E
	adds r0, r4, #0
	movs r1, #7
	bl FUN_080ef86c
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #2
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_081A726E:
	cmp r5, #0x28
	bne _081A7280
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081A7280:
	ldr r1, _081A729C @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A7296
	cmp r5, #0x78
	ble _081A7296
	ldr r0, _081A72A0 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081A7296:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A729C: .4byte 0x0000046E
_081A72A0: .4byte 0x0000046B

	thumb_func_start FUN_081a72a4
FUN_081a72a4: @ 0x081A72A4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081A72BC @ =0x0000046D
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081A72C0
	movs r0, #0
	strb r0, [r2]
	movs r0, #1
	b _081A72C2
	.align 2, 0
_081A72BC: .4byte 0x0000046D
_081A72C0:
	movs r0, #0
_081A72C2:
	adds r5, r0, #0
	cmp r5, #0
	beq _081A72FA
	movs r2, #1
	ldr r1, _081A72E0 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A72E4
	ldr r1, [r4, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081A72EE
	.align 2, 0
_081A72E0: .4byte 0x0000025D
_081A72E4:
	ldr r1, [r4, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_081A72EE:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_080136b4
	b _081A7342
_081A72FA:
	cmp r1, #0x1a
	ble _081A733C
	adds r0, r4, #0
	movs r1, #9
	bl FUN_080ef86c
	ldr r3, _081A7330 @ =FUN_081a734c
	movs r2, #0xd
	ldr r0, _081A7334 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A7338 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
	b _081A7342
	.align 2, 0
_081A7330: .4byte FUN_081a734c
_081A7334: .4byte 0x0000046D
_081A7338: .4byte 0x0000046B
_081A733C:
	ldr r1, _081A7348 @ =0x0000046E
	adds r0, r4, r1
	strb r5, [r0]
_081A7342:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A7348: .4byte 0x0000046E

	thumb_func_start FUN_081a734c
FUN_081a734c: @ 0x081A734C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _081A7364 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A7368
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A736A
	.align 2, 0
_081A7364: .4byte 0x0000046D
_081A7368:
	movs r0, #0
_081A736A:
	cmp r0, #0
	beq _081A73B6
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r6, r1
	bl FUN_08013698
	ldr r2, _081A7390 @ =0x0000025D
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A7394
	ldr r2, [r6, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081A73A2
	.align 2, 0
_081A7390: .4byte 0x0000025D
_081A7394:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	movs r2, #2
	rsbs r2, r2, #0
	ldr r1, [r0, #8]
	ands r1, r2
	str r1, [r0, #8]
_081A73A2:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x3c
	strh r0, [r1]
_081A73B6:
	ldr r0, [r6, #0x44]
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1, #8]
	cmp r0, #3
	bne _081A73CE
	ldrh r0, [r1, #0xe]
	cmp r0, #4
	bne _081A73CE
	movs r0, #0xee
	bl PlaySound_082406e0
_081A73CE:
	ldr r1, _081A756C @ =0x0000046E
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A73DA
	b _081A7566
_081A73DA:
	adds r0, r6, #0
	bl FUN_081ab110
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r6, r2
	ldr r2, _081A7570 @ =0x0000055C
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r6, r0
	adds r2, #4
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _081A7574 @ =0x00000564
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r4, #0
	strb r0, [r6, #5]
	adds r2, #5
	adds r0, r6, r2
	ldrb r1, [r0]
	subs r2, #0xfd
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _081A7578 @ =0x00000566
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _081A757C @ =0x00000567
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r1, [r0]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r1, r6, r0
	adds r2, #0xfe
	adds r0, r6, r2
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _081A7580 @ =0x0000056C
	adds r0, r6, r1
	ldrb r1, [r0]
	subs r2, #0x15
	adds r0, r6, r2
	strb r1, [r0]
	ldr r1, _081A7584 @ =0x00000572
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r2, #0xdf
	adds r0, r6, r2
	movs r5, #0
	strh r1, [r0]
	movs r1, #0xae
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	subs r2, #0x3a
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #0x9e
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r2, _081A7588 @ =0x0000046B
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _081A758C @ =0x0000046C
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _081A7590 @ =0x0000024E
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xbc
	adds r0, r6, r2
	strh r4, [r0]
	ldr r2, _081A7594 @ =0x00000544
	adds r0, r6, r2
	strh r4, [r0]
	subs r2, #0xde
	adds r0, r6, r2
	strh r4, [r0]
	movs r2, #0xea
	lsls r2, r2, #1
	adds r0, r6, r2
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r4, [r0]
	adds r2, #5
	adds r0, r6, r2
	strb r5, [r0]
	adds r2, #0x3f
	adds r0, r6, r2
	strb r5, [r0]
	ldr r2, _081A7598 @ =0x00000482
	adds r0, r6, r2
	strh r1, [r0]
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #0x1a
	adds r0, r6, r2
	str r4, [r0]
	adds r1, #8
	adds r0, r6, r1
	str r4, [r0]
	subs r2, #0x10
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #0x1e
	adds r0, r6, r1
	strh r4, [r0]
	adds r2, #1
	adds r0, r6, r2
	strb r5, [r0]
	subs r1, #0x30
	adds r0, r6, r1
	strb r5, [r0]
	subs r2, #0x35
	adds r0, r6, r2
	movs r1, #8
	bl ClearMemory
	ldr r1, _081A759C @ =0x00000464
	adds r0, r6, r1
	strh r4, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r6, r2
	strh r4, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r4, [r0]
	ldr r1, _081A75A0 @ =0x0825223C
	adds r0, r6, #0
	ldr r2, _081A75A4 @ =0x00000982
	bl FUN_080e6768
	movs r2, #0xa8
	lsls r2, r2, #3
	adds r0, r6, r2
	strb r5, [r0]
	ldr r1, _081A75A8 @ =0x00000541
	adds r0, r6, r1
	strb r5, [r0]
	adds r2, #2
	adds r1, r6, r2
	movs r0, #0xff
	strb r0, [r1]
	movs r1, #0xa9
	lsls r1, r1, #3
	adds r0, r6, r1
	str r4, [r0]
	adds r2, #0xa
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #5
	adds r0, r6, r1
	strb r5, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r5, [r0]
	adds r1, #2
	adds r0, r6, r1
	strb r5, [r0]
	adds r0, r6, #0
	bl FUN_080eeee0
_081A7566:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A756C: .4byte 0x0000046E
_081A7570: .4byte 0x0000055C
_081A7574: .4byte 0x00000564
_081A7578: .4byte 0x00000566
_081A757C: .4byte 0x00000567
_081A7580: .4byte 0x0000056C
_081A7584: .4byte 0x00000572
_081A7588: .4byte 0x0000046B
_081A758C: .4byte 0x0000046C
_081A7590: .4byte 0x0000024E
_081A7594: .4byte 0x00000544
_081A7598: .4byte 0x00000482
_081A759C: .4byte 0x00000464
_081A75A0: .4byte 0x0825223C
_081A75A4: .4byte 0x00000982
_081A75A8: .4byte 0x00000541

	thumb_func_start FUN_081a75ac
FUN_081a75ac: @ 0x081A75AC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _081A75D4 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A75D8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A75DA
	.align 2, 0
_081A75D4: .4byte 0x0000046D
_081A75D8:
	movs r0, #0
_081A75DA:
	cmp r0, #0
	beq _081A7606
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r4, #5]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_081a9774
	movs r0, #2
	movs r7, #0xca
	lsls r7, r7, #4
	adds r2, r5, r7
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_081A7606:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r6, #0
	str r6, [sp]
	mov r0, sp
	ldr r2, _081A7660 @ =0x05000002
	bl CpuSet
	ldr r1, _081A7664 @ =0x00000CBA
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0xc8
	cmp r0, #3
	bls _081A7626
	adds r2, #0x64
_081A7626:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r2
	blt _081A7678
	ldr r3, _081A7668 @ =FUN_081a7838
	movs r2, #0x26
	ldr r0, _081A766C @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A7670 @ =0x0000046B
	adds r0, r4, r1
	strb r6, [r0]
	ldr r7, _081A7674 @ =0x00000553
	adds r0, r4, r7
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r6, [r0]
	b _081A7824
	.align 2, 0
_081A7660: .4byte 0x05000002
_081A7664: .4byte 0x00000CBA
_081A7668: .4byte FUN_081a7838
_081A766C: .4byte 0x0000046D
_081A7670: .4byte 0x0000046B
_081A7674: .4byte 0x00000553
_081A7678:
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _081A768C
	movs r6, #1
	ldrh r0, [r1]
	adds r0, #0xa
	b _081A7692
_081A768C:
	movs r6, #2
	ldrh r0, [r1]
	adds r0, #0x28
_081A7692:
	strh r0, [r1]
	ldrb r0, [r4, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _081A76B8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	muls r0, r6, r0
	cmp r0, #0
	blt _081A76BC
	asrs r1, r0, #0xc
	b _081A76C2
	.align 2, 0
_081A76B8: .4byte 0x085B0A08
_081A76BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A76C2:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081A76DA
	asrs r2, r0, #0xc
	b _081A76E0
_081A76DA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081A76E0:
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	ldr r3, _081A7728 @ =0x00002EE0
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #0xc
	bl FUN_081aae88
	movs r2, #0
	mov r8, r2
	movs r3, #0
	ldr r7, _081A772C @ =0x00000CAA
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r3, r0
	blt _081A7706
	b _081A7824
_081A7706:
	movs r2, #0xd0
	mov ip, r2
	ldr r6, _081A7730 @ =0x085B0A08
	ldr r7, _081A7734 @ =0x00000674
	adds r2, r5, r7
_081A7710:
	mov r0, ip
	muls r0, r3, r0
	adds r0, r0, r5
	movs r1, #2
	ldr r7, _081A7738 @ =0x00000705
	adds r0, r0, r7
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A773C
	movs r0, #1
	b _081A773E
	.align 2, 0
_081A7728: .4byte 0x00002EE0
_081A772C: .4byte 0x00000CAA
_081A7730: .4byte 0x085B0A08
_081A7734: .4byte 0x00000674
_081A7738: .4byte 0x00000705
_081A773C:
	movs r0, #0
_081A773E:
	cmp r0, #0
	beq _081A7812
	mov r0, ip
	muls r0, r3, r0
	adds r0, r0, r5
	movs r1, #5
	ldr r7, _081A775C @ =0x00000705
	adds r0, r0, r7
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A7760
	movs r0, #1
	b _081A7762
	.align 2, 0
_081A775C: .4byte 0x00000705
_081A7760:
	movs r0, #0
_081A7762:
	cmp r0, #0
	bne _081A7812
	mov r0, r8
	cmp r0, #0
	beq _081A7778
	cmp r0, #1
	beq _081A77C0
	ldrh r0, [r4, #8]
	strh r0, [r2]
	ldrh r0, [r4, #0xc]
	b _081A780C
_081A7778:
	ldrb r0, [r4, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r7, #0
	ldrsh r1, [r0, r7]
	mov sb, r1
	movs r0, #0x36
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081A779A
	asrs r1, r0, #0xc
	b _081A77A0
_081A779A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A77A0:
	ldrh r0, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r4, #5]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r7, [r0, r1]
	mov sb, r7
	movs r0, #0x36
	mov r7, sb
	muls r7, r0, r7
	adds r0, r7, #0
	cmp r0, #0
	bge _081A77FE
	b _081A7802
_081A77C0:
	ldrb r0, [r4, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081A77DE
	asrs r1, r0, #0xc
	b _081A77E4
_081A77DE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A77E4:
	ldrh r0, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrb r0, [r4, #5]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081A7802
_081A77FE:
	asrs r1, r0, #0xc
	b _081A7808
_081A7802:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A7808:
	ldrh r0, [r4, #0xc]
	subs r0, r0, r1
_081A780C:
	strh r0, [r2, #4]
	movs r0, #1
	add r8, r0
_081A7812:
	adds r2, #0xd0
	adds r3, #1
	ldr r1, _081A7834 @ =0x00000CAA
	adds r0, r5, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r3, r0
	bge _081A7824
	b _081A7710
_081A7824:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A7834: .4byte 0x00000CAA

	thumb_func_start FUN_081a7838
FUN_081a7838: @ 0x081A7838
	bx lr
	.align 2, 0

	thumb_func_start FUN_081a783c
FUN_081a783c: @ 0x081A783C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _081A7854 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A7858
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A785A
	.align 2, 0
_081A7854: .4byte 0x0000046D
_081A7858:
	movs r0, #0
_081A785A:
	cmp r0, #0
	beq _081A786E
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081A786E:
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r5, #0
	str r5, [sp]
	mov r0, sp
	ldr r2, _081A78B8 @ =0x05000002
	bl CpuSet
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0xff
	ble _081A78C8
	ldr r3, _081A78BC @ =FUN_081a795c
	movs r2, #0x22
	ldr r0, _081A78C0 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A78C4 @ =0x0000046B
	adds r0, r4, r1
	strb r5, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	b _081A7954
	.align 2, 0
_081A78B8: .4byte 0x05000002
_081A78BC: .4byte FUN_081a795c
_081A78C0: .4byte 0x0000046D
_081A78C4: .4byte 0x0000046B
_081A78C8:
	ldr r3, _081A78DC @ =0x00000484
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0x1d
	bgt _081A78E0
	movs r5, #1
	adds r0, r2, #0
	adds r0, #0xa
	b _081A78E6
	.align 2, 0
_081A78DC: .4byte 0x00000484
_081A78E0:
	movs r5, #2
	adds r0, r2, #0
	adds r0, #0x28
_081A78E6:
	strh r0, [r1]
	ldrb r0, [r4, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r1, #0xff
	ands r3, r1
	ldr r2, _081A790C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081A7910
	asrs r1, r0, #0xc
	b _081A7916
	.align 2, 0
_081A790C: .4byte 0x085B0A08
_081A7910:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A7916:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _081A792E
	asrs r2, r0, #0xc
	b _081A7934
_081A792E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081A7934:
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #0xc
	bl FUN_081aae88
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0x18
	movs r3, #0
	bl FUN_081aaba8
_081A7954:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081a795c
FUN_081a795c: @ 0x081A795C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	str r1, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _081A7988 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A798C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A798E
	.align 2, 0
_081A7988: .4byte 0x0000046D
_081A798C:
	movs r0, #0
_081A798E:
	cmp r0, #0
	beq _081A799A
	ldr r3, _081A79B0 @ =0x00000C45
	adds r1, r7, r3
	movs r0, #0
	strb r0, [r1]
_081A799A:
	ldr r1, _081A79B0 @ =0x00000C45
	adds r0, r7, r1
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _081A79B4
	ldrb r3, [r6, #5]
	b _081A79BE
	.align 2, 0
_081A79B0: .4byte 0x00000C45
_081A79B4:
	ldrb r0, [r6, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r0, #0xff
	ands r3, r0
_081A79BE:
	movs r0, #0x7f
	ands r0, r1
	lsrs r4, r0, #4
	ldr r2, _081A79E0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081A79E4
	asrs r1, r0, #0xc
	b _081A79EA
	.align 2, 0
_081A79E0: .4byte 0x085B0A08
_081A79E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A79EA:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081A7A02
	asrs r2, r0, #0xc
	b _081A7A08
_081A7A02:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081A7A08:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldr r3, _081A7A4C @ =0x00000C45
	adds r1, r7, r3
	ldrb r0, [r1]
	adds r0, #0xc
	strb r0, [r1]
	movs r0, #0
	str r0, [sp, #4]
	mov r8, r0
	ldr r1, _081A7A50 @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	blt _081A7A2C
	b _081A7BCC
_081A7A2C:
	movs r3, #0xd0
	mov sl, r3
_081A7A30:
	mov r1, sl
	mov r0, r8
	muls r0, r1, r0
	adds r0, r0, r7
	movs r1, #2
	ldr r2, _081A7A54 @ =0x00000705
	adds r0, r0, r2
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A7A58
	movs r0, #1
	b _081A7A5A
	.align 2, 0
_081A7A4C: .4byte 0x00000C45
_081A7A50: .4byte 0x00000CAA
_081A7A54: .4byte 0x00000705
_081A7A58:
	movs r0, #0
_081A7A5A:
	movs r3, #1
	add r3, r8
	mov sb, r3
	cmp r0, #0
	bne _081A7A66
	b _081A7BBC
_081A7A66:
	mov r1, sl
	mov r0, r8
	muls r0, r1, r0
	adds r0, r0, r7
	movs r1, #5
	ldr r2, _081A7A80 @ =0x00000705
	adds r0, r0, r2
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A7A84
	movs r0, #1
	b _081A7A86
	.align 2, 0
_081A7A80: .4byte 0x00000705
_081A7A84:
	movs r0, #0
_081A7A86:
	adds r5, r0, #0
	movs r3, #1
	add r3, r8
	mov sb, r3
	cmp r5, #0
	beq _081A7A94
	b _081A7BBC
_081A7A94:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	mov r1, sb
	bl Div
	mov r2, sl
	mov r1, r8
	muls r1, r2, r1
	adds r4, r7, r1
	ldr r3, _081A7AE0 @ =0x0000071C
	adds r1, r4, r3
	strh r0, [r1]
	ldr r1, _081A7AE4 @ =0x0000071E
	adds r0, r4, r1
	strh r5, [r0]
	movs r2, #0x14
	ldrsh r0, [r6, r2]
	mov r1, sb
	bl Div
	movs r3, #0xe4
	lsls r3, r3, #3
	adds r1, r4, r3
	strh r0, [r1]
	ldr r0, [sp, #4]
	cmp r0, #0
	beq _081A7AEC
	cmp r0, #1
	beq _081A7B40
	ldrh r1, [r6, #8]
	ldr r2, _081A7AE8 @ =0x00000674
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	subs r3, #0xa8
	adds r0, r4, r3
	strh r1, [r0]
	b _081A7BB6
	.align 2, 0
_081A7AE0: .4byte 0x0000071C
_081A7AE4: .4byte 0x0000071E
_081A7AE8: .4byte 0x00000674
_081A7AEC:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _081A7B0C @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	ldr r2, _081A7B0C @ =0x085B0A08
	cmp r0, #0
	blt _081A7B10
	asrs r3, r0, #0xc
	b _081A7B16
	.align 2, 0
_081A7B0C: .4byte 0x085B0A08
_081A7B10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_081A7B16:
	mov r0, sl
	mov r1, r8
	muls r1, r0, r1
	adds r1, r7, r1
	ldrh r0, [r6, #8]
	subs r0, r0, r3
	ldr r3, _081A7B3C @ =0x00000674
	adds r1, r1, r3
	strh r0, [r1]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	cmp r0, #0
	bge _081A7B94
	b _081A7B9C
	.align 2, 0
_081A7B3C: .4byte 0x00000674
_081A7B40:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _081A7B64 @ =0x085B0A08
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r3, #0
	cmp r0, #0
	blt _081A7B68
	asrs r3, r0, #0xc
	b _081A7B6E
	.align 2, 0
_081A7B64: .4byte 0x085B0A08
_081A7B68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_081A7B6E:
	mov r0, sl
	mov r1, r8
	muls r1, r0, r1
	adds r1, r7, r1
	ldrh r0, [r6, #8]
	subs r0, r0, r3
	ldr r3, _081A7B98 @ =0x00000674
	adds r1, r1, r3
	strh r0, [r1]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _081A7B9C
_081A7B94:
	asrs r2, r0, #0xc
	b _081A7BA2
	.align 2, 0
_081A7B98: .4byte 0x00000674
_081A7B9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081A7BA2:
	mov r3, sl
	mov r1, r8
	muls r1, r3, r1
	adds r1, r7, r1
	ldrh r0, [r6, #0xc]
	subs r0, r0, r2
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r1, r1, r2
	strh r0, [r1]
_081A7BB6:
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
_081A7BBC:
	mov r8, sb
	ldr r1, _081A7C18 @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	bge _081A7BCC
	b _081A7A30
_081A7BCC:
	ldr r3, _081A7C1C @ =0x0000FFFF
	adds r0, r6, #0
	movs r1, #0x40
	movs r2, #0xc
	bl FUN_081aae88
	ldr r3, [sp]
	cmp r3, #0x3c
	ble _081A7C08
	ldr r4, _081A7C20 @ =FUN_081a7c2c
	movs r3, #0x23
	ldr r0, _081A7C24 @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A7C28 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
_081A7C08:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A7C18: .4byte 0x00000CAA
_081A7C1C: .4byte 0x0000FFFF
_081A7C20: .4byte FUN_081a7c2c
_081A7C24: .4byte 0x0000046D
_081A7C28: .4byte 0x0000046B

	thumb_func_start FUN_081a7c2c
FUN_081a7c2c: @ 0x081A7C2C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	ldr r2, _081A7C54 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A7C58
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A7C5A
	.align 2, 0
_081A7C54: .4byte 0x0000046D
_081A7C58:
	movs r0, #0
_081A7C5A:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r6
	mov sb, r1
	cmp r0, #0
	beq _081A7CAE
	adds r0, r6, #0
	bl FUN_081ae4a4
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, #4
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	strb r0, [r6, #5]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r1, _081A7CF0 @ =0xFFEFFFFF
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xca
	lsls r0, r0, #4
	adds r2, r4, r0
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081A7CAE:
	ldrb r0, [r6, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_081a9774
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _081A7CF4 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A7D00
	ldr r1, _081A7CF8 @ =0x000004B7
	adds r0, r6, r1
	strb r2, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r2, _081A7CFC @ =0x0000046E
	adds r7, r6, r2
	b _081A7D82
	.align 2, 0
_081A7CF0: .4byte 0xFFEFFFFF
_081A7CF4: .4byte 0x0000025D
_081A7CF8: .4byte 0x000004B7
_081A7CFC: .4byte 0x0000046E
_081A7D00:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	ldr r1, _081A7D70 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081A7D74 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, r2
	bne _081A7D3A
	ldrb r0, [r7]
	cmp r0, #0
	bne _081A7D3A
	cmp r4, #1
	bne _081A7D2C
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081A7D86
_081A7D2C:
	cmp r4, #0
	bne _081A7D3A
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081A7D86
_081A7D3A:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081A7D4C
	movs r3, #6
_081A7D4C:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081A7D78
	ldr r0, [r5, #8]
	mov r2, r8
	orrs r0, r2
	b _081A7D80
	.align 2, 0
_081A7D70: .4byte 0x000004B7
_081A7D74: .4byte 0x0000046E
_081A7D78:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081A7D80:
	str r0, [r5, #8]
_081A7D82:
	movs r0, #0
	strb r0, [r7]
_081A7D86:
	adds r0, r6, #0
	movs r1, #0x12
	movs r2, #6
	movs r3, #0
	bl FUN_081aaba8
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_081aa614
	movs r1, #0x10
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081A7DF8
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r6, r0
	ldr r1, _081A7DE8 @ =0xFFFFFEFF
	ldrh r0, [r2]
	ands r1, r0
	movs r3, #0
	movs r5, #0
	strh r1, [r2]
	ldr r4, _081A7DEC @ =FUN_081a7e18
	movs r2, #0x24
	ldr r0, _081A7DF0 @ =0x0000046D
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A7DF4 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r5, [r0]
	b _081A7E08
	.align 2, 0
_081A7DE8: .4byte 0xFFFFFEFF
_081A7DEC: .4byte FUN_081a7e18
_081A7DF0: .4byte 0x0000046D
_081A7DF4: .4byte 0x0000046B
_081A7DF8:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081A7E08:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081a7e18
FUN_081a7e18: @ 0x081A7E18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	str r1, [sp, #0xc]
	ldr r0, _081A7E80 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A7E36
	movs r0, #0
	strb r0, [r1]
_081A7E36:
	ldrb r0, [r6, #5]
	add r4, sp, #8
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081a9774
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r7, [sp, #8]
	ldr r1, _081A7E84 @ =0x0000025D
	adds r0, r6, r1
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	bne _081A7E90
	ldr r0, _081A7E88 @ =0x000004B7
	adds r5, r6, r0
	strb r2, [r5]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r7, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	mov r8, r5
	ldr r1, _081A7E8C @ =0x0000046E
	adds r1, r1, r6
	mov sb, r1
	b _081A7F12
	.align 2, 0
_081A7E80: .4byte 0x0000046D
_081A7E84: .4byte 0x0000025D
_081A7E88: .4byte 0x000004B7
_081A7E8C: .4byte 0x0000046E
_081A7E90:
	ldr r0, [r6, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, r2, r3
	ldr r1, _081A7F00 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	mov r8, r0
	ldr r0, _081A7F04 @ =0x0000046E
	adds r0, r0, r6
	mov sb, r0
	cmp r1, r2
	bne _081A7ECC
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A7ECC
	cmp r7, #1
	bne _081A7EBE
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081A7F18
_081A7EBE:
	cmp r7, #0
	bne _081A7ECC
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081A7F18
_081A7ECC:
	mov r1, r8
	strb r2, [r1]
	movs r5, #4
	adds r0, r7, #0
	ands r0, r5
	movs r3, #4
	cmp r0, #0
	beq _081A7EDE
	movs r3, #6
_081A7EDE:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r7, r0
	cmp r7, #0
	beq _081A7F08
	ldr r0, [r4, #8]
	orrs r0, r5
	b _081A7F10
	.align 2, 0
_081A7F00: .4byte 0x000004B7
_081A7F04: .4byte 0x0000046E
_081A7F08:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081A7F10:
	str r0, [r4, #8]
_081A7F12:
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
_081A7F18:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_081aa614
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0xc
	bl FUN_081aae88
	ldr r0, [sp, #0xc]
	cmp r0, #0x28
	ble _081A7FFC
	ldrb r0, [r6, #5]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_081a9774
	movs r1, #0x9f
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _081A7F72
	mov r0, r8
	strb r2, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	b _081A7FE2
_081A7F72:
	ldr r0, [r6, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	adds r2, r2, r3
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, r2
	bne _081A7FA6
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #0
	bne _081A7FA6
	cmp r4, #1
	bne _081A7F98
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081A7FE8
_081A7F98:
	cmp r4, #0
	bne _081A7FA6
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081A7FE8
_081A7FA6:
	mov r0, r8
	strb r2, [r0]
	movs r7, #4
	adds r0, r4, #0
	ands r0, r7
	movs r3, #4
	cmp r0, #0
	beq _081A7FB8
	movs r3, #6
_081A7FB8:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081A7FD8
	ldr r0, [r5, #8]
	orrs r0, r7
	b _081A7FE0
_081A7FD8:
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081A7FE0:
	str r0, [r5, #8]
_081A7FE2:
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
_081A7FE8:
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_081aa614
	ldr r0, _081A800C @ =0x0000046B
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_081A7FFC:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A800C: .4byte 0x0000046B

	thumb_func_start FUN_081a8010
FUN_081a8010: @ 0x081A8010
	push {lr}
	ldr r2, _081A8024 @ =0x0000046D
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A8020
	movs r0, #0
	strb r0, [r1]
_081A8020:
	pop {r0}
	bx r0
	.align 2, 0
_081A8024: .4byte 0x0000046D

	thumb_func_start FUN_081a8028
FUN_081a8028: @ 0x081A8028
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r5, r0, #0
	ldr r0, _081A8048 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A804C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A804E
	.align 2, 0
_081A8048: .4byte 0x0000046D
_081A804C:
	movs r0, #0
_081A804E:
	cmp r0, #0
	beq _081A80B4
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080e64b4
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _081A81C4 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _081A81C8 @ =0x0000021E
	adds r0, r5, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	ldr r4, _081A81CC @ =0x00000202
	adds r0, r5, r4
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081A81D0 @ =0x000003DB
	bl PlaySound_082406e0
_081A80B4:
	adds r4, r5, #0
	adds r4, #8
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x28
	str r0, [sp, #4]
	movs r0, #0x10
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	movs r3, #0x80
	bl FUN_080dd8d4
	ldr r0, _081A81D4 @ =0x0000046D
	adds r0, r5, r0
	str r0, [sp, #0x40]
	adds r6, r4, #0
	movs r1, #0xcd
	lsls r1, r1, #1
	adds r7, r5, r1
	ldr r2, _081A81D8 @ =0x000001DF
	adds r2, r2, r5
	mov sb, r2
	movs r3, #0x90
	lsls r3, r3, #3
	adds r3, r3, r5
	mov r8, r3
	ldr r4, _081A81DC @ =0x0000046B
	adds r4, r5, r4
	str r4, [sp, #0x38]
	ldr r0, _081A81E0 @ =0x00000553
	adds r0, r5, r0
	str r0, [sp, #0x48]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r1, r5, r1
	str r1, [sp, #0x50]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r2, r5, r2
	str r2, [sp, #0x4c]
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r3, r5, r3
	str r3, [sp, #0x54]
	ldr r4, _081A81E4 @ =0x00000469
	adds r4, r5, r4
	str r4, [sp, #0x58]
	ldr r0, _081A81E8 @ =0x0000046A
	adds r0, r5, r0
	str r0, [sp, #0x34]
	ldr r1, _081A81EC @ =0x00000484
	adds r1, r5, r1
	str r1, [sp, #0x44]
	ldr r2, _081A81F0 @ =0x0000046C
	adds r2, r5, r2
	str r2, [sp, #0x3c]
	movs r3, #0xc1
	lsls r3, r3, #1
	adds r3, r3, r5
	mov sl, r3
	movs r4, #0xb
_081A8132:
	adds r0, r6, #0
	bl FUN_081acab4
	subs r4, #1
	cmp r4, #0
	bge _081A8132
	adds r0, r5, #0
	bl FUN_081ab5b8
	ldrh r0, [r7]
	cmp r0, #0
	beq _081A81A0
	movs r4, #8
	ldrsh r0, [r5, r4]
	str r0, [sp, #0xc]
	movs r1, #0xa
	ldrsh r0, [r5, r1]
	str r0, [sp, #0x10]
	movs r2, #0xc
	ldrsh r0, [r5, r2]
	str r0, [sp, #0x14]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0x18]
	movs r4, #0xd0
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r0, [r0]
	str r0, [sp, #0x1c]
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x20]
	movs r2, #0x94
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldrh r0, [r5]
	str r0, [sp, #0x28]
	ldr r1, _081A81F4 @ =0xFFFF0000
	ldr r0, [sp, #0x2c]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x2c]
	add r1, sp, #0x2c
	add r3, sp, #0xc
	str r3, [r1, #4]
	ldrh r0, [r7]
	bl Script_ExecById
_081A81A0:
	mov r4, sb
	ldrb r0, [r4]
	mov r2, r8
	ldrh r1, [r2]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _081A81FC
	ldr r0, _081A81F8 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0xe2
	lsls r4, r4, #2
	adds r2, r2, r4
	movs r1, #1
	lsls r1, r3
	b _081A820E
	.align 2, 0
_081A81C4: .4byte 0xFFFEBE3F
_081A81C8: .4byte 0x0000021E
_081A81CC: .4byte 0x00000202
_081A81D0: .4byte 0x000003DB
_081A81D4: .4byte 0x0000046D
_081A81D8: .4byte 0x000001DF
_081A81DC: .4byte 0x0000046B
_081A81E0: .4byte 0x00000553
_081A81E4: .4byte 0x00000469
_081A81E8: .4byte 0x0000046A
_081A81EC: .4byte 0x00000484
_081A81F0: .4byte 0x0000046C
_081A81F4: .4byte 0xFFFF0000
_081A81F8: .4byte 0x030046A0
_081A81FC:
	ldr r0, _081A826C @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_081A820E:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r3, _081A8270 @ =FUN_080e48d0
	movs r1, #0x10
	movs r0, #0
	movs r2, #1
	ldr r4, [sp, #0x40]
	strb r2, [r4]
	ldr r4, [sp, #0x38]
	strb r0, [r4]
	ldr r4, [sp, #0x48]
	strb r1, [r4]
	ldr r1, [sp, #0x50]
	str r3, [r1]
	movs r3, #0
	ldr r4, [sp, #0x4c]
	strh r0, [r4]
	movs r1, #2
	ldr r4, [sp, #0x54]
	strb r2, [r4]
	ldr r4, [sp, #0x58]
	strb r3, [r4]
	ldr r3, [sp, #0x34]
	strb r1, [r3]
	ldr r4, [sp, #0x44]
	str r0, [r4]
	ldr r0, [sp, #0x3c]
	strb r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	mov r3, sl
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
	ldr r4, _081A8274 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A826C: .4byte 0x030046A0
_081A8270: .4byte FUN_080e48d0
_081A8274: .4byte 0x0000046B

	thumb_func_start FUN_081a8278
FUN_081a8278: @ 0x081A8278
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081A8298 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A829C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A829E
	.align 2, 0
_081A8298: .4byte 0x0000046C
_081A829C:
	movs r0, #0
_081A829E:
	cmp r0, #0
	beq _081A82E4
	ldr r3, _081A8310 @ =0x00000CA4
	adds r0, r7, r3
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	ldr r6, _081A8314 @ =0x00000CA8
	adds r0, r7, r6
	movs r2, #0
	strh r4, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	ldr r6, _081A8318 @ =0x0000046D
	adds r0, r5, r6
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _081A831C @ =0x00000553
	adds r0, r5, r2
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_081aa9dc
_081A82E4:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _081A8320 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A8328
	ldr r0, _081A8324 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081A8338
	.align 2, 0
_081A8310: .4byte 0x00000CA4
_081A8314: .4byte 0x00000CA8
_081A8318: .4byte 0x0000046D
_081A831C: .4byte 0x00000553
_081A8320: .4byte 0x0000A02F
_081A8324: .4byte 0x00000482
_081A8328:
	ldr r1, _081A835C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081A8338
	movs r0, #1
	strh r0, [r2]
_081A8338:
	ldr r3, _081A8360 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A8364
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _081A837C
	.align 2, 0
_081A835C: .4byte 0x00000482
_081A8360: .4byte 0x0000025D
_081A8364:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_081A837C:
	ldr r1, _081A83B4 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _081A839E
	rsbs r2, r2, #0
_081A839E:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _081A83B8
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _081A83AC
	rsbs r2, r2, #0
_081A83AC:
	cmp r2, #0x20
	bgt _081A83B8
	movs r0, #1
	b _081A8422
	.align 2, 0
_081A83B4: .4byte 0x000004A4
_081A83B8:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _081A83C4
	cmp r1, #0
	beq _081A8420
_081A83C4:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _081A83E8 @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081A83EC
	asrs r1, r0, #0xc
	b _081A83F2
	.align 2, 0
_081A83E8: .4byte 0x085B0A08
_081A83EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A83F2:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _081A8410 @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _081A8414
	asrs r1, r0, #0xc
	b _081A841A
	.align 2, 0
_081A8410: .4byte 0x085B0A08
_081A8414:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A841A:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_081A8420:
	movs r0, #0
_081A8422:
	cmp r0, #0
	beq _081A84D8
	ldr r0, _081A8484 @ =0x000004A4
	adds r3, r5, r0
	ldr r2, [r3]
	ldr r0, _081A8488 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r0, [r3]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r1]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081A8490
	ldr r3, _081A848C @ =0xFFFFFF00
	adds r1, r1, r3
	b _081A849E
	.align 2, 0
_081A8484: .4byte 0x000004A4
_081A8488: .4byte 0x03002BE0
_081A848C: .4byte 0xFFFFFF00
_081A8490:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081A849E
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081A849E:
	cmp r1, #0
	bge _081A84A4
	rsbs r1, r1, #0
_081A84A4:
	cmp r1, #0x20
	ble _081A84D8
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081A84D0 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081A84D4 @ =0x0000046A
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	b _081A8508
	.align 2, 0
_081A84D0: .4byte 0x00000469
_081A84D4: .4byte 0x0000046A
_081A84D8:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_081ab90c
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #0x12
	bl FUN_081aae88
	adds r0, r7, #0
	bl FUN_081aa44c
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_081aaa00
	ldr r0, _081A8510 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A8508:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A8510: .4byte 0x00000484

	thumb_func_start FUN_081a8514
FUN_081a8514: @ 0x081A8514
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081A853C @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A8540
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A8542
	.align 2, 0
_081A853C: .4byte 0x0000046C
_081A8540:
	movs r0, #0
_081A8542:
	cmp r0, #0
	beq _081A861C
	ldr r0, _081A867C @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r7, #8]
	str r1, [r7, #0xc]
	ldr r3, _081A8680 @ =0x00000472
	adds r4, r7, r3
	ldr r1, _081A8684 @ =0xFFFFFE00
	adds r0, r1, #0
	ldrh r2, [r4]
	adds r0, r0, r2
	movs r5, #0
	movs r6, #0
	strh r0, [r7, #0xa]
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r1, r7, #0
	adds r1, #8
	mov r0, r8
	bl FUN_081ab024
	ldrh r0, [r4]
	strh r0, [r7, #0xa]
	movs r0, #0x40
	strb r0, [r7, #5]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r1, [r0]
	movs r4, #1
	ldr r2, _081A8688 @ =0x0000046D
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081A868C @ =0x0000046B
	adds r0, r7, r3
	strb r5, [r0]
	adds r2, #0xe6
	adds r0, r7, r2
	strb r4, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r7, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r6, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081A8690 @ =0x00000474
	adds r2, r7, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r1, r7, r2
	str r6, [sp]
	mov r0, sp
	ldr r2, _081A8694 @ =0x05000002
	bl CpuSet
	ldr r0, _081A8698 @ =0x00000CB7
	add r0, r8
	strb r4, [r0]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r4, sp, #4
	adds r0, r4, #0
	bl FUN_081acd70
	ldrh r0, [r4]
	subs r0, #0x64
	strh r0, [r4]
	ldrh r0, [r4, #4]
	adds r0, #0x80
	strh r0, [r4, #4]
	adds r0, r4, #0
	bl FUN_081acd70
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldrh r0, [r4]
	adds r0, #0x64
	strh r0, [r4]
	ldrh r0, [r4, #4]
	adds r0, #0x80
	strh r0, [r4, #4]
	adds r0, r4, #0
	bl FUN_081acd70
_081A861C:
	ldr r3, _081A869C @ =0x00000484
	adds r4, r7, r3
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	cmp r0, #0x77
	bgt _081A862C
	b _081A873C
_081A862C:
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_08013984
	ldr r2, [r7, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r5, r7, r2
	movs r3, #0
	ldrsh r1, [r5, r3]
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	ble _081A86A4
	movs r2, #0xa
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081A86A0 @ =0x00000469
	adds r0, r7, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r2, [r0]
	ldr r2, _081A869C @ =0x00000484
	adds r0, r7, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _081A873C
	.align 2, 0
_081A867C: .4byte 0x03002BE0
_081A8680: .4byte 0x00000472
_081A8684: .4byte 0xFFFFFE00
_081A8688: .4byte 0x0000046D
_081A868C: .4byte 0x0000046B
_081A8690: .4byte 0x00000474
_081A8694: .4byte 0x05000002
_081A8698: .4byte 0x00000CB7
_081A869C: .4byte 0x00000484
_081A86A0: .4byte 0x00000469
_081A86A4:
	movs r6, #0x1e
	ldr r0, [r4]
	movs r1, #0xe
	bl Mod
	cmp r0, #0
	bne _081A86C4
	ldr r0, _081A86EC @ =0x00000CB7
	add r0, r8
	ldrb r1, [r0]
	adds r1, #0xc
	strb r1, [r0]
	adds r0, r7, #0
	adds r0, #8
	bl FUN_081ac9a4
_081A86C4:
	ldr r1, _081A86EC @ =0x00000CB7
	add r1, r8
	ldrh r0, [r5]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r5]
	ldr r2, _081A86F0 @ =0x085B0A08
	ldrb r0, [r7, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081A86F4
	asrs r0, r0, #0xc
	b _081A86FA
	.align 2, 0
_081A86EC: .4byte 0x00000CB7
_081A86F0: .4byte 0x085B0A08
_081A86F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A86FA:
	adds r1, r0, #0
	ldrb r0, [r7, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081A8710
	asrs r2, r0, #0xc
	b _081A8716
_081A8710:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081A8716:
	ldrb r0, [r7, #5]
	adds r0, #9
	strb r0, [r7, #5]
	ldrh r0, [r7, #0x10]
	adds r0, r0, r1
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	adds r0, r7, #0
	movs r1, #8
	movs r2, #4
	movs r3, #0x9b
	lsls r3, r3, #3
	bl FUN_081aae88
	mov r0, r8
	bl FUN_081aa44c
_081A873C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081a8748
FUN_081a8748: @ 0x081A8748
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081A8760 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A8764
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A8766
	.align 2, 0
_081A8760: .4byte 0x0000046C
_081A8764:
	movs r0, #0
_081A8766:
	cmp r0, #0
	beq _081A87A4
	ldr r4, _081A87EC @ =FUN_081a75ac
	movs r3, #0x25
	ldr r2, _081A87F0 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A87F4 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081A87A4:
	ldr r1, _081A87F4 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081A8800
	adds r0, r5, #0
	bl FUN_081a97a4
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081A87F8 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _081A87FC @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	b _081A880A
	.align 2, 0
_081A87EC: .4byte FUN_081a75ac
_081A87F0: .4byte 0x0000046D
_081A87F4: .4byte 0x0000046B
_081A87F8: .4byte 0x00000484
_081A87FC: .4byte 0xFFEFFFFF
_081A8800:
	ldr r2, _081A8810 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A880A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A8810: .4byte 0x00000484

	thumb_func_start FUN_081a8814
FUN_081a8814: @ 0x081A8814
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _081A8840 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A8844
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A8846
	.align 2, 0
_081A8840: .4byte 0x0000046C
_081A8844:
	movs r0, #0
_081A8846:
	cmp r0, #0
	beq _081A88C6
	ldr r3, _081A889C @ =0x00000256
	adds r0, r5, r3
	ldrh r1, [r0]
	ldr r0, _081A88A0 @ =0x00000C4E
	add r0, sl
	strh r1, [r0]
	ldrh r6, [r0]
	movs r7, #0xcf
	lsls r7, r7, #4
	add r7, sl
	ldr r0, _081A88A4 @ =0x030046A4
	mov r8, r0
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Mod
	adds r4, r0, #0
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r6, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r7]
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A88A8
	adds r0, #4
	b _081A88B4
	.align 2, 0
_081A889C: .4byte 0x00000256
_081A88A0: .4byte 0x00000C4E
_081A88A4: .4byte 0x030046A4
_081A88A8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r6, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A88B4:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r7, #2]
	mov r1, sb
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r7, #4]
_081A88C6:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r1, _081A88F4 @ =0x0000A02F
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A88FC
	ldr r0, _081A88F8 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081A890C
	.align 2, 0
_081A88F4: .4byte 0x0000A02F
_081A88F8: .4byte 0x00000482
_081A88FC:
	ldr r1, _081A8930 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081A890C
	movs r0, #1
	strh r0, [r2]
_081A890C:
	ldr r3, _081A8934 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081A8938
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _081A8950
	.align 2, 0
_081A8930: .4byte 0x00000482
_081A8934: .4byte 0x0000025D
_081A8938:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_081A8950:
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	adds r3, r0, #0
	cmp r1, #0x80
	ble _081A896C
	ldr r2, _081A8968 @ =0xFFFFFF00
	adds r1, r1, r2
	b _081A897A
	.align 2, 0
_081A8968: .4byte 0xFFFFFF00
_081A896C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081A897A
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081A897A:
	adds r6, r1, #0
	adds r0, r6, #0
	cmp r6, #0
	bge _081A8984
	rsbs r0, r6, #0
_081A8984:
	cmp r0, #8
	ble _081A89D4
	ldr r2, _081A89A4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _081A89A8
	asrs r0, r0, #0xc
	b _081A89AE
	.align 2, 0
_081A89A4: .4byte 0x085B0A08
_081A89A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A89AE:
	adds r1, r0, #0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _081A89C2
	asrs r2, r0, #0xc
	b _081A89C8
_081A89C2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081A89C8:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
_081A89D4:
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	adds r2, r5, #0
	adds r2, #0x10
	ldrh r0, [r5, #0x10]
	ldrh r1, [r5, #8]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r3, [r3, #4]
	adds r1, r1, r3
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081A8A1C
	cmp r1, #0
	blt _081A8A1C
	ldr r0, _081A8A20 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081A8A1C
	ldr r0, _081A8A24 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081A8A28
_081A8A1C:
	movs r7, #0
	b _081A8A36
	.align 2, 0
_081A8A20: .4byte 0x030046A8
_081A8A24: .4byte 0x030046AC
_081A8A28:
	ldr r0, _081A8AD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_081A8A36:
	ldr r2, _081A8AD4 @ =0x00000C4E
	add r2, sl
	mov r8, r2
	ldrh r0, [r2]
	cmp r0, r7
	beq _081A8A88
	mov r4, sp
	movs r2, #0xcf
	lsls r2, r2, #4
	add r2, sl
	ldrh r1, [r2]
	mov r0, sp
	ldrh r0, [r0]
	subs r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl Div
	ldrh r1, [r5, #0x10]
	adds r1, r1, r0
	strh r1, [r5, #0x10]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl Div
	ldrh r1, [r5, #0x14]
	adds r1, r1, r0
	strh r1, [r5, #0x14]
_081A8A88:
	ldr r3, _081A8AD8 @ =0x0000A410
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #0xc
	bl FUN_081aae88
	adds r0, r6, #0
	cmp r6, #0
	bge _081A8A9C
	rsbs r0, r6, #0
_081A8A9C:
	cmp r0, #7
	bgt _081A8AE0
	mov r2, r8
	ldrh r0, [r2]
	cmp r0, r7
	bne _081A8B06
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081A8ADC @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _081A8B06
	.align 2, 0
_081A8AD0: .4byte 0x030046A4
_081A8AD4: .4byte 0x00000C4E
_081A8AD8: .4byte 0x0000A410
_081A8ADC: .4byte 0x00000484
_081A8AE0:
	cmp r6, #0
	ble _081A8AF8
	ldr r1, _081A8AF4 @ =0x00000482
	adds r0, r5, r1
	ldrh r0, [r0]
	lsls r0, r0, #1
	ldrb r2, [r5, #5]
	adds r0, r0, r2
	b _081A8B04
	.align 2, 0
_081A8AF4: .4byte 0x00000482
_081A8AF8:
	ldr r3, _081A8B20 @ =0x00000482
	adds r0, r5, r3
	ldrh r1, [r0]
	lsls r1, r1, #1
	ldrb r0, [r5, #5]
	subs r0, r0, r1
_081A8B04:
	strb r0, [r5, #5]
_081A8B06:
	ldr r0, _081A8B24 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A8B20: .4byte 0x00000482
_081A8B24: .4byte 0x00000484

	thumb_func_start FUN_081a8b28
FUN_081a8b28: @ 0x081A8B28
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081A8B40 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A8B44
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A8B46
	.align 2, 0
_081A8B40: .4byte 0x0000046C
_081A8B44:
	movs r0, #0
_081A8B46:
	cmp r0, #0
	beq _081A8BEC
	ldr r1, _081A8B9C @ =0x000005A4
	adds r0, r5, r1
	ldr r3, [r0]
	movs r2, #0
	ldr r4, _081A8BA0 @ =0x0000046D
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081A8BA4 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _081A8BA8 @ =0x00000553
	adds r0, r5, r1
	strb r2, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrb r4, [r5, #5]
	ldr r2, _081A8BAC @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _081A8BB0
	asrs r1, r0, #0xc
	b _081A8BB6
	.align 2, 0
_081A8B9C: .4byte 0x000005A4
_081A8BA0: .4byte 0x0000046D
_081A8BA4: .4byte 0x0000046B
_081A8BA8: .4byte 0x00000553
_081A8BAC: .4byte 0x085B0A08
_081A8BB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A8BB6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _081A8BD0
	asrs r2, r0, #0xc
	b _081A8BD6
_081A8BD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081A8BD6:
	movs r0, #0
	strh r2, [r3, #4]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r1, r5, r4
	strh r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #2
	strh r0, [r1]
_081A8BEC:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_081aae88
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A8C74
	adds r0, r5, #0
	bl FUN_081a97a4
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	movs r3, #1
	ldr r6, _081A8C64 @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r3, [r0]
	ldr r4, _081A8C68 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r0, r5, r4
	str r1, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081A8C6C @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _081A8C70 @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _081A8C7E
	.align 2, 0
_081A8C64: .4byte 0x0000046D
_081A8C68: .4byte 0x0000046B
_081A8C6C: .4byte 0x0000046A
_081A8C70: .4byte 0x00000484
_081A8C74:
	ldr r0, _081A8C84 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A8C7E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081A8C84: .4byte 0x00000484

	thumb_func_start FUN_081a8c88
FUN_081a8c88: @ 0x081A8C88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x24
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r6, [r0]
	ldr r2, _081A8CAC @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A8CB0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A8CB2
	.align 2, 0
_081A8CAC: .4byte 0x0000046C
_081A8CB0:
	movs r0, #0
_081A8CB2:
	cmp r0, #0
	bne _081A8CB8
	b _081A8DEA
_081A8CB8:
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r7, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _081A8D38 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r2, [r0]
	ldr r0, _081A8D3C @ =0x00000472
	adds r4, r7, r0
	ldr r1, _081A8D40 @ =0xFFFFFE00
	adds r0, r1, #0
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r7, #0xa]
	ldr r2, [r7, #0x44]
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	adds r1, r7, #0
	adds r1, #8
	adds r0, r6, #0
	bl FUN_081ab024
	ldrh r0, [r4]
	strh r0, [r7, #0xa]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r3, r7, r4
	ldrb r4, [r0]
	movs r5, #0x18
	ldr r2, _081A8D44 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081A8D48
	asrs r1, r0, #0xc
	b _081A8D4E
	.align 2, 0
_081A8D38: .4byte 0x0000046D
_081A8D3C: .4byte 0x00000472
_081A8D40: .4byte 0xFFFFFE00
_081A8D44: .4byte 0x085B0A08
_081A8D48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A8D4E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081A8D68 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081A8D6C
	asrs r0, r0, #0xc
	b _081A8D72
	.align 2, 0
_081A8D68: .4byte 0x085B0A08
_081A8D6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A8D72:
	movs r1, #0
	strh r0, [r3, #4]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r0, [r0]
	strb r0, [r7, #5]
	movs r4, #0xe1
	lsls r4, r4, #1
	adds r2, r7, r4
	movs r0, #0x28
	strh r0, [r2]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #4
	movs r3, #0xca
	lsls r3, r3, #4
	adds r4, r6, r3
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	ldr r0, _081A8DC0 @ =0x0000019D
	bl PlaySound_082406e0
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_08013984
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081A8DC4
	movs r0, #1
	b _081A8DC6
	.align 2, 0
_081A8DC0: .4byte 0x0000019D
_081A8DC4:
	movs r0, #0
_081A8DC6:
	cmp r0, #0
	beq _081A8DD8
	ldr r0, _081A8DD4 @ =0xFFFFFDFF
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	b _081A8DDE
	.align 2, 0
_081A8DD4: .4byte 0xFFFFFDFF
_081A8DD8:
	adds r0, r7, #0
	bl FUN_081acd2c
_081A8DDE:
	ldr r0, [r7, #0x44]
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_081A8DEA:
	ldr r2, _081A8E24 @ =0x00000484
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #9
	bgt _081A8E2C
	add r4, sp, #4
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081A8E28 @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	strh r0, [r4, #2]
	movs r5, #0
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
_081A8E12:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081aab38
	adds r5, #1
	cmp r5, #2
	ble _081A8E12
	b _081A8EB0
	.align 2, 0
_081A8E24: .4byte 0x00000484
_081A8E28: .4byte 0x05000002
_081A8E2C:
	cmp r0, #0x13
	bgt _081A8E64
	add r4, sp, #0xc
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081A8E60 @ =0x05000002
	bl CpuSet
	movs r0, #0x18
	strh r0, [r4, #2]
	movs r5, #0
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r0, r0, r7
	mov r8, r0
_081A8E4E:
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081aab38
	adds r5, #1
	cmp r5, #5
	ble _081A8E4E
	b _081A8EB0
	.align 2, 0
_081A8E60: .4byte 0x05000002
_081A8E64:
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	cmp r0, #0x3b
	bgt _081A8EB0
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081A8E98 @ =0x05000002
	bl CpuSet
	movs r5, #0
_081A8E82:
	cmp r5, #2
	bgt _081A8E9C
	movs r0, #0x2c
	strh r0, [r4, #2]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081aab38
	b _081A8EAA
	.align 2, 0
_081A8E98: .4byte 0x05000002
_081A8E9C:
	movs r0, #0x3e
	strh r0, [r4, #2]
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_081aab38
_081A8EAA:
	adds r5, #1
	cmp r5, #5
	ble _081A8E82
_081A8EB0:
	ldr r2, _081A8ED8 @ =0x00000484
	adds r4, r7, r2
	ldr r0, [r4]
	movs r1, #0xc
	bl Mod
	cmp r0, #0
	bne _081A8EC8
	adds r0, r7, #0
	adds r0, #8
	bl FUN_081ac9a4
_081A8EC8:
	ldr r0, [r4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _081A8F00
	movs r4, #0
	b _081A8EF4
	.align 2, 0
_081A8ED8: .4byte 0x00000484
_081A8EDC:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _081A8EF2
	movs r0, #0xd0
	muls r0, r4, r0
	adds r0, r0, r6
	ldr r2, _081A8FB0 @ =0x00000674
	adds r0, r0, r2
	bl FUN_081acbc0
_081A8EF2:
	adds r4, #1
_081A8EF4:
	ldr r3, _081A8FB4 @ =0x00000CAA
	adds r0, r6, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r4, r0
	blt _081A8EDC
_081A8F00:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r7, #0
	movs r1, #4
	movs r2, #4
	bl FUN_081aae88
	adds r0, r6, #0
	bl FUN_081aa44c
	movs r0, #0x10
	mov r2, r8
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081A8FCC
	ldr r0, _081A8FB8 @ =0xFFEFFFFF
	ands r1, r0
	str r1, [r2]
	adds r0, r7, #0
	bl FUN_081a97a4
	add r2, sp, #0x1c
	adds r4, r7, #0
	adds r4, #8
	ldr r3, _081A8FBC @ =0x000004A4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r1, [r0, #0xc]
	ldrh r0, [r7, #8]
	subs r1, r1, r0
	movs r5, #0
	movs r6, #0
	strh r1, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r4, #0xee
	lsls r4, r4, #1
	adds r1, r7, r4
	strb r0, [r1]
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r1, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r5, [r0]
	ldr r4, _081A8FC0 @ =0x00000469
	adds r0, r7, r4
	strb r5, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r7, r4
	str r6, [r0]
	ldr r1, _081A8FC4 @ =0x0000046C
	adds r0, r7, r1
	strb r2, [r0]
	ldr r0, _081A8FC8 @ =0x00000145
	bl PlaySound_082406e0
	movs r2, #0xaa
	lsls r2, r2, #2
	adds r0, r7, r2
	bl FUN_080139a0
	adds r0, r7, #0
	bl FUN_081acd2c
	b _081A8FD6
	.align 2, 0
_081A8FB0: .4byte 0x00000674
_081A8FB4: .4byte 0x00000CAA
_081A8FB8: .4byte 0xFFEFFFFF
_081A8FBC: .4byte 0x000004A4
_081A8FC0: .4byte 0x00000469
_081A8FC4: .4byte 0x0000046C
_081A8FC8: .4byte 0x00000145
_081A8FCC:
	ldr r3, _081A8FE4 @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A8FD6:
	add sp, #0x24
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A8FE4: .4byte 0x00000484

	thumb_func_start FUN_081a8fe8
FUN_081a8fe8: @ 0x081A8FE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _081A9014 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A9018
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A901A
	.align 2, 0
_081A9014: .4byte 0x0000046C
_081A9018:
	movs r0, #0
_081A901A:
	movs r3, #0xca
	lsls r3, r3, #4
	add r3, sb
	mov r8, r3
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r6, r5, r6
	str r6, [sp, #8]
	cmp r0, #0
	beq _081A907A
	movs r3, #0x20
	ldr r0, _081A9094 @ =0x00000474
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r4, #0
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	mov r6, r8
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r3, [r0]
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	ldr r1, _081A9098 @ =0xFFEFFFFF
	ldr r6, [sp, #8]
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #9
	rsbs r0, r0, #0
	mov r2, r8
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
_081A907A:
	ldr r3, _081A909C @ =0x00000484
	adds r0, r5, r3
	ldr r0, [r0]
	cmp r0, #0x50
	ble _081A90A0
	adds r0, r5, #0
	movs r1, #4
	movs r2, #4
	movs r3, #0
	bl FUN_081aae88
	b _081A90AE
	.align 2, 0
_081A9094: .4byte 0x00000474
_081A9098: .4byte 0xFFEFFFFF
_081A909C: .4byte 0x00000484
_081A90A0:
	movs r3, #0x80
	lsls r3, r3, #5
	adds r0, r5, #0
	movs r1, #0xc
	movs r2, #4
	bl FUN_081aae88
_081A90AE:
	movs r6, #0
	ldr r1, _081A9170 @ =0x00000CAA
	add r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	bge _081A9124
	mov r3, sp
	adds r7, r5, #0
	adds r7, #8
	ldr r0, _081A9174 @ =0x00000472
	adds r0, r0, r5
	mov sl, r0
	mov ip, r1
	mov r4, sb
_081A90CC:
	movs r1, #0xd0
	adds r2, r6, #0
	muls r2, r1, r2
	add r2, sb
	ldr r0, _081A9178 @ =0x00000674
	adds r2, r2, r0
	ldrh r0, [r2]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r0, #0xfa
	lsls r0, r0, #7
	cmp r1, r0
	ble _081A9116
	mov r0, sl
	ldrh r1, [r0]
	ldr r2, _081A917C @ =0x00000676
	adds r0, r4, r2
	strh r1, [r0]
_081A9116:
	adds r4, #0xd0
	adds r6, #1
	mov r1, ip
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	blt _081A90CC
_081A9124:
	mov r0, sb
	bl FUN_081aa44c
	movs r1, #0x10
	ldr r3, [sp, #8]
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081A915E
	ldr r2, [r5, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #8
	mov r6, r8
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r0, #0x20
	ldr r1, _081A9180 @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0xf7
	lsls r0, r0, #2
	bl PlaySound_082406e0
_081A915E:
	movs r1, #8
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081A9184
	movs r0, #1
	b _081A9186
	.align 2, 0
_081A9170: .4byte 0x00000CAA
_081A9174: .4byte 0x00000472
_081A9178: .4byte 0x00000674
_081A917C: .4byte 0x00000676
_081A9180: .4byte 0x00000474
_081A9184:
	movs r0, #0
_081A9186:
	cmp r0, #0
	beq _081A9200
	ldrh r0, [r5, #0xa]
	subs r0, #0x10
	movs r4, #0
	strh r0, [r5, #0xa]
	mov r0, sb
	bl FUN_081aa44c
	cmp r0, #0
	bge _081A9200
	movs r1, #6
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r4, [r0]
	ldr r6, _081A91F0 @ =0x00000469
	adds r0, r5, r6
	strb r4, [r0]
	ldr r2, _081A91F4 @ =0x0000046A
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1c
	adds r1, r5, r3
	movs r0, #0
	str r0, [r1]
	adds r6, #3
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081A91F8 @ =0x00000472
	adds r0, r5, r1
	ldrh r0, [r0]
	strh r0, [r5, #0xa]
	subs r3, #0x10
	adds r2, r5, r3
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r5, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _081A91FC @ =0x00000B57
	add r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _081A920A
	.align 2, 0
_081A91F0: .4byte 0x00000469
_081A91F4: .4byte 0x0000046A
_081A91F8: .4byte 0x00000472
_081A91FC: .4byte 0x00000B57
_081A9200:
	ldr r6, _081A921C @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A920A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A921C: .4byte 0x00000484

	thumb_func_start FUN_081a9220
FUN_081a9220: @ 0x081A9220
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081A924C @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A9250
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A9252
	.align 2, 0
_081A924C: .4byte 0x0000046C
_081A9250:
	movs r0, #0
_081A9252:
	cmp r0, #0
	beq _081A9296
	movs r3, #0x20
	ldr r5, _081A9280 @ =0x00000474
	adds r2, r4, r5
	ldrh r1, [r2]
	adds r0, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0xca
	lsls r2, r2, #4
	add r2, r8
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ands r0, r3
	cmp r0, #0
	beq _081A9284
	movs r0, #1
	b _081A9286
	.align 2, 0
_081A9280: .4byte 0x00000474
_081A9284:
	movs r0, #0
_081A9286:
	cmp r0, #0
	beq _081A9296
	bl FUN_081f746c
	movs r0, #0xf7
	lsls r0, r0, #2
	bl PlaySound_082406e0
_081A9296:
	movs r7, #0xa
	ldrsh r1, [r4, r7]
	ldr r0, _081A92C4 @ =0xFFFFF800
	ldrh r6, [r4, #0xa]
	cmp r1, r0
	ble _081A9324
	mov r3, sp
	ldrb r5, [r4, #5]
	ldr r2, _081A92C8 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	cmp r0, #0
	blt _081A92CC
	asrs r1, r0, #0xc
	b _081A92D2
	.align 2, 0
_081A92C4: .4byte 0xFFFFF800
_081A92C8: .4byte 0x085B0A08
_081A92CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081A92D2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _081A92EC
	asrs r0, r0, #0xc
	b _081A92F2
_081A92EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081A92F2:
	strh r0, [r3, #4]
	adds r0, r6, #0
	subs r0, #0x64
	strh r0, [r4, #0xa]
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	cmp r0, #0
	bne _081A932A
	movs r3, #0xa
	ldrsh r1, [r4, r3]
	ldr r5, _081A931C @ =0x00000472
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r1, r0
	bge _081A932A
	movs r0, #1
	str r0, [r2]
	ldr r0, _081A9320 @ =0x000001DF
	bl PlaySound_082406e0
	b _081A932A
	.align 2, 0
_081A931C: .4byte 0x00000472
_081A9320: .4byte 0x000001DF
_081A9324:
	movs r0, #0xf8
	lsls r0, r0, #8
	strh r0, [r4, #0xa]
_081A932A:
	ldr r7, _081A9344 @ =0x00000484
	adds r0, r4, r7
	ldr r0, [r0]
	cmp r0, #0x1e
	ble _081A9348
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #4
	movs r3, #0
	bl FUN_081aae88
	b _081A9354
	.align 2, 0
_081A9344: .4byte 0x00000484
_081A9348:
	ldr r3, _081A9414 @ =0x0000A410
	adds r0, r4, #0
	movs r1, #0xc
	movs r2, #6
	bl FUN_081aae88
_081A9354:
	movs r6, #0
	ldr r1, _081A9418 @ =0x00000CAA
	add r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	bge _081A93D8
	add r3, sp, #8
	adds r5, r4, #0
	adds r5, #8
	str r5, [sp, #0x10]
	movs r7, #0xd0
	mov sl, r7
	ldr r0, _081A941C @ =0x00000472
	adds r0, r0, r4
	mov sb, r0
	mov r5, r8
	mov ip, r1
_081A9378:
	mov r2, sl
	muls r2, r6, r2
	add r2, r8
	ldr r1, _081A9420 @ =0x00000674
	adds r2, r2, r1
	ldrh r0, [r2]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldr r7, [sp, #0x10]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	movs r0, #0xfa
	lsls r0, r0, #7
	cmp r1, r0
	ble _081A93CA
	ldr r0, _081A9424 @ =0x00000676
	adds r2, r5, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r7, sb
	ldrh r1, [r7]
	cmp r0, r1
	bge _081A93CA
	strh r1, [r2]
_081A93CA:
	adds r5, #0xd0
	adds r6, #1
	mov r1, ip
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r6, r0
	blt _081A9378
_081A93D8:
	mov r0, r8
	bl FUN_081aa44c
	cmp r0, #0
	bge _081A949C
	ldr r3, _081A9428 @ =0x00000B57
	add r3, r8
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #4
	ble _081A9438
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r1, #0
	strb r1, [r0]
	ldr r5, _081A942C @ =0x00000469
	adds r0, r4, r5
	strb r1, [r0]
	ldr r7, _081A9430 @ =0x0000046A
	adds r0, r4, r7
	strb r1, [r0]
	ldr r2, _081A9434 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #4
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	b _081A94A6
	.align 2, 0
_081A9414: .4byte 0x0000A410
_081A9418: .4byte 0x00000CAA
_081A941C: .4byte 0x00000472
_081A9420: .4byte 0x00000674
_081A9424: .4byte 0x00000676
_081A9428: .4byte 0x00000B57
_081A942C: .4byte 0x00000469
_081A9430: .4byte 0x0000046A
_081A9434: .4byte 0x00000484
_081A9438:
	ldr r5, _081A9494 @ =0x00000484
	adds r0, r4, r5
	ldr r0, [r0]
	cmp r0, #0x3c
	ble _081A949C
	movs r2, #6
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r4, r7
	movs r1, #0
	strb r1, [r0]
	subs r5, #0x1b
	adds r0, r4, r5
	strb r1, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r2, [r0]
	ldr r2, _081A9494 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r5, #3
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	adds r7, #8
	adds r0, r4, r7
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	ldr r0, _081A9498 @ =0x00000474
	adds r2, r4, r0
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	b _081A94A6
	.align 2, 0
_081A9494: .4byte 0x00000484
_081A9498: .4byte 0x00000474
_081A949C:
	ldr r2, _081A94B8 @ =0x00000484
	adds r1, r4, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081A94A6:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A94B8: .4byte 0x00000484

	thumb_func_start FUN_081a94bc
FUN_081a94bc: @ 0x081A94BC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r2, _081A94DC @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A94E0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A94E2
	.align 2, 0
_081A94DC: .4byte 0x0000046C
_081A94E0:
	movs r0, #0
_081A94E2:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r5, r4, r3
	cmp r0, #0
	beq _081A9544
	movs r7, #0xb4
	lsls r7, r7, #3
	adds r0, r4, r7
	ldr r2, [r0]
	movs r1, #1
	ldr r3, _081A9584 @ =0x0000046D
	adds r0, r4, r3
	movs r3, #0
	strb r1, [r0]
	ldr r7, _081A9588 @ =0x0000046B
	adds r0, r4, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r3, [r0]
	movs r7, #0xca
	lsls r7, r7, #4
	adds r2, r6, r7
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, _081A958C @ =0x0000FFC0
	strh r0, [r1]
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r3, [r0]
	ldr r1, _081A9590 @ =0xFFEFFFFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
_081A9544:
	ldr r3, _081A9594 @ =0x0000FFFF
	adds r0, r4, #0
	movs r1, #6
	movs r2, #0xc
	bl FUN_081aae88
	adds r0, r6, #0
	bl FUN_081aa44c
	movs r1, #0x10
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081A95E0
	ldr r2, [r4, #0x44]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #1
	movs r3, #0xca
	lsls r3, r3, #4
	adds r1, r6, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081A9598
	movs r0, #1
	b _081A959A
	.align 2, 0
_081A9584: .4byte 0x0000046D
_081A9588: .4byte 0x0000046B
_081A958C: .4byte 0x0000FFC0
_081A9590: .4byte 0xFFEFFFFF
_081A9594: .4byte 0x0000FFFF
_081A9598:
	movs r0, #0
_081A959A:
	cmp r0, #0
	beq _081A95B4
	movs r0, #0xf7
	lsls r0, r0, #2
	bl PlaySound_082406e0
	ldr r0, _081A95B0 @ =0xFFFFFEFF
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	b _081A95BA
	.align 2, 0
_081A95B0: .4byte 0xFFFFFEFF
_081A95B4:
	ldr r0, _081A95F0 @ =0x00000145
	bl PlaySound_082406e0
_081A95BA:
	movs r2, #7
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r4, r7
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081A95F4 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r2, [r0]
	ldr r2, _081A95F8 @ =0x00000484
	adds r0, r4, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_081A95E0:
	ldr r7, _081A95F8 @ =0x00000484
	adds r1, r4, r7
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081A95F0: .4byte 0x00000145
_081A95F4: .4byte 0x00000469
_081A95F8: .4byte 0x00000484

	thumb_func_start FUN_081a95fc
FUN_081a95fc: @ 0x081A95FC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r6, _081A961C @ =0x0000046C
	adds r1, r5, r6
	ldrb r0, [r1]
	cmp r0, #0
	beq _081A9620
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081A9622
	.align 2, 0
_081A961C: .4byte 0x0000046C
_081A9620:
	movs r0, #0
_081A9622:
	cmp r0, #0
	beq _081A9636
	movs r0, #0x20
	movs r1, #0xca
	lsls r1, r1, #4
	adds r2, r2, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	b _081A9708
_081A9636:
	ldr r2, _081A9654 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0x46
	beq _081A9670
	cmp r0, #0x46
	bgt _081A965E
	cmp r0, #0x1e
	beq _081A9670
	cmp r0, #0x1e
	bgt _081A9658
	cmp r0, #0xa
	beq _081A9670
	b _081A9676
	.align 2, 0
_081A9654: .4byte 0x00000484
_081A9658:
	cmp r0, #0x32
	beq _081A9670
	b _081A9676
_081A965E:
	cmp r0, #0x5a
	beq _081A9670
	cmp r0, #0x5a
	bgt _081A966C
	cmp r0, #0x50
	beq _081A9670
	b _081A9676
_081A966C:
	cmp r0, #0x5f
	bne _081A9676
_081A9670:
	adds r0, r5, #0
	bl FUN_081ab50c
_081A9676:
	ldr r6, _081A96EC @ =0x00000484
	adds r0, r5, r6
	ldr r0, [r0]
	cmp r0, #0x64
	ble _081A9692
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _081A9692
	adds r0, r5, #0
	adds r0, #8
	bl FUN_081acab4
_081A9692:
	ldr r0, _081A96EC @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	cmp r0, #0x78
	ble _081A9704
	ldr r3, _081A96F0 @ =FUN_081a8028
	movs r1, #0x11
	ldr r2, _081A96F4 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	ldr r6, _081A96F8 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081A96FC @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _081A9700 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	b _081A9708
	.align 2, 0
_081A96EC: .4byte 0x00000484
_081A96F0: .4byte FUN_081a8028
_081A96F4: .4byte 0x0000046D
_081A96F8: .4byte 0x0000046B
_081A96FC: .4byte 0x00000469
_081A9700: .4byte 0x0000046C
_081A9704:
	adds r0, #1
	str r0, [r1]
_081A9708:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081a9710
FUN_081a9710: @ 0x081A9710
	ldr r1, _081A971C @ =0x00000634
	adds r0, r0, r1
	ldr r1, _081A9720 @ =0x085ADEA8
	str r1, [r0]
	bx lr
	.align 2, 0
_081A971C: .4byte 0x00000634
_081A9720: .4byte 0x085ADEA8

	thumb_func_start FUN_081a9724
FUN_081a9724: @ 0x081A9724
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081A976A
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x20
	movs r2, #0xca
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081A9750
	movs r0, #1
	b _081A9752
_081A9750:
	movs r0, #0
_081A9752:
	cmp r0, #0
	bne _081A976A
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _081A9770 @ =0x00000C42
	adds r1, r1, r2
	ldrh r0, [r5]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_081A976A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081A9770: .4byte 0x00000C42

	thumb_func_start FUN_081a9774
FUN_081a9774: @ 0x081A9774
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	cmp r1, #4
	ble _081A9798
	movs r0, #8
	subs r0, r0, r1
	str r0, [r3]
	movs r0, #1
	b _081A979C
_081A9798:
	str r1, [r3]
	movs r0, #0
_081A979C:
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081a97a4
FUN_081a97a4: @ 0x081A97A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	str r0, [sp, #0x20]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #0x24]
	ldr r2, [sp, #0x20]
	ldr r3, _081A9800 @ =0x000004A4
	adds r0, r2, r3
	ldr r0, [r0]
	str r0, [sp, #0x28]
	ldrb r0, [r2, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	str r0, [sp, #0x2c]
	movs r1, #1
	rsbs r1, r1, #0
	add r0, sp, #0xc
_081A97D8:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _081A97D8
	movs r4, #0
	str r4, [sp, #0x34]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x38]
	ldr r1, [sp, #0x24]
	ldr r2, _081A9804 @ =0x00000CB8
	adds r0, r1, r2
	ldrb r3, [r0]
	cmp r3, #2
	bne _081A9808
	ldr r6, [sp, #0x2c]
	adds r6, #1
	movs r0, #3
	ands r6, r0
	b _081A9836
	.align 2, 0
_081A9800: .4byte 0x000004A4
_081A9804: .4byte 0x00000CB8
_081A9808:
	cmp r3, #3
	bne _081A9834
	ldr r2, _081A9828 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A982C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _081A9830 @ =0x0203B400
	adds r0, r0, r4
	ldrh r0, [r0]
	ldr r1, [sp, #0x2c]
	adds r6, r1, r0
	ands r6, r3
	b _081A9836
	.align 2, 0
_081A9828: .4byte 0x030046B8
_081A982C: .4byte 0x000003FF
_081A9830: .4byte 0x0203B400
_081A9834:
	ldr r6, [sp, #0x2c]
_081A9836:
	ldr r2, [sp, #0x24]
	ldr r4, _081A9898 @ =0x00000CB8
	adds r3, r2, r4
	ldrb r0, [r3]
	cmp r0, #0x10
	bls _081A9860
	ldr r1, [sp, #0x20]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r4, [sp, #0x24]
	ldr r2, _081A989C @ =0x00000CB9
	adds r1, r4, r2
	movs r2, #0
	strb r0, [r1]
	strb r2, [r3]
_081A9860:
	movs r3, #3
	str r3, [sp, #0x30]
_081A9864:
	ldr r4, [sp, #0x24]
	ldr r1, _081A989C @ =0x00000CB9
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, r6, r0
	cmp r0, #0
	bge _081A9874
	rsbs r0, r0, #0
_081A9874:
	cmp r0, #2
	bne _081A987A
	b _081A9C1A
_081A987A:
	ldr r2, [sp, #0x2c]
	subs r0, r6, r2
	cmp r0, #0
	bge _081A9884
	rsbs r0, r0, #0
_081A9884:
	cmp r0, #2
	bne _081A988A
	b _081A9C1A
_081A988A:
	cmp r6, #1
	beq _081A98BC
	cmp r6, #1
	bgt _081A98A0
	cmp r6, #0
	beq _081A98AA
	b _081A9910
	.align 2, 0
_081A9898: .4byte 0x00000CB8
_081A989C: .4byte 0x00000CB9
_081A98A0:
	cmp r6, #2
	beq _081A98DC
	cmp r6, #3
	beq _081A98F0
	b _081A9910
_081A98AA:
	ldr r3, [sp, #0x20]
	ldr r4, _081A98B8 @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r7, r0, #1
	str r1, [sp, #0x58]
	b _081A991A
	.align 2, 0
_081A98B8: .4byte 0x00000256
_081A98BC:
	ldr r0, [sp, #0x20]
	ldr r2, _081A98D4 @ =0x00000256
	adds r1, r0, r2
	ldr r3, _081A98D8 @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	ldrh r2, [r1]
	adds r7, r0, r2
	str r1, [sp, #0x58]
	b _081A991A
	.align 2, 0
_081A98D4: .4byte 0x00000256
_081A98D8: .4byte 0x030046A4
_081A98DC:
	ldr r3, [sp, #0x20]
	ldr r4, _081A98EC @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	subs r7, r0, #1
	str r1, [sp, #0x58]
	b _081A991A
	.align 2, 0
_081A98EC: .4byte 0x00000256
_081A98F0:
	ldr r0, [sp, #0x20]
	ldr r2, _081A9908 @ =0x00000256
	adds r1, r0, r2
	ldrh r2, [r1]
	ldr r3, _081A990C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r0, [r0, r4]
	subs r7, r2, r0
	str r1, [sp, #0x58]
	b _081A991A
	.align 2, 0
_081A9908: .4byte 0x00000256
_081A990C: .4byte 0x030046A4
_081A9910:
	ldr r1, [sp, #0x20]
	ldr r2, _081A992C @ =0x00000256
	adds r0, r1, r2
	ldrh r7, [r0]
	str r0, [sp, #0x58]
_081A991A:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9930
	adds r0, #4
	b _081A993C
	.align 2, 0
_081A992C: .4byte 0x00000256
_081A9930:
	ldr r3, _081A9958 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A993C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	str r0, [sp, #0x3c]
	ldr r0, [sp, #0x58]
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A995C
	adds r0, #4
	b _081A9968
	.align 2, 0
_081A9958: .4byte 0x030046A4
_081A995C:
	ldr r1, _081A9980 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9968:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sl, r0
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9984
	adds r0, #4
	b _081A9990
	.align 2, 0
_081A9980: .4byte 0x030046A4
_081A9984:
	ldr r2, _081A99D4 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9990:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x40]
	add r5, sp, #0x10
	ldr r3, _081A99D4 @ =0x030046A4
	mov r8, r3
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r5]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A99D8
	adds r0, #4
	b _081A99E4
	.align 2, 0
_081A99D4: .4byte 0x030046A4
_081A99D8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A99E4:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r5, #2]
	mov r4, sb
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	add r4, sp, #0x10
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9A08
	adds r0, #4
	b _081A9A14
_081A9A08:
	ldr r1, _081A9A28 @ =0x030046A4
	ldr r0, [r1]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9A14:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A9A2C
	cmp r2, #2
	beq _081A9A30
	b _081A9A34
	.align 2, 0
_081A9A28: .4byte 0x030046A4
_081A9A2C:
	ldrb r0, [r4, #4]
	b _081A9A32
_081A9A30:
	ldrb r0, [r4]
_081A9A32:
	subs r1, r1, r0
_081A9A34:
	str r1, [sp, #0x44]
	ldr r2, [sp, #0x58]
	ldrh r5, [r2]
	add r3, sp, #0x10
	mov sb, r3
	ldr r4, _081A9A7C @ =0x030046A4
	ldr r0, [r4]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r3, _081A9A7C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x10
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9A80
	adds r0, #4
	b _081A9A8C
	.align 2, 0
_081A9A7C: .4byte 0x030046A4
_081A9A80:
	ldr r3, _081A9AB8 @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9A8C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	mov r4, sb
	strh r1, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r2, [sp, #0x58]
	ldrh r4, [r2]
	add r5, sp, #0x10
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9ABC
	adds r0, #4
	b _081A9AC8
	.align 2, 0
_081A9AB8: .4byte 0x030046A4
_081A9ABC:
	ldr r3, _081A9ADC @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9AC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A9AE0
	cmp r2, #2
	beq _081A9AE4
	b _081A9AE8
	.align 2, 0
_081A9ADC: .4byte 0x030046A4
_081A9AE0:
	ldrb r0, [r5, #4]
	b _081A9AE6
_081A9AE4:
	ldrb r0, [r5]
_081A9AE6:
	subs r1, r1, r0
_081A9AE8:
	ldr r4, [sp, #0x44]
	subs r2, r4, r1
	adds r0, r1, #0
	adds r0, #0xff
	asrs r0, r0, #8
	adds r1, r4, #0
	adds r1, #0xff
	asrs r1, r1, #8
	subs r0, r0, r1
	lsls r1, r0, #8
	movs r0, #0x43
	ldr r3, [sp, #0x40]
	ands r3, r0
	cmp r3, #0
	beq _081A9B08
	b _081A9C1A
_081A9B08:
	cmp r2, #0
	beq _081A9BFE
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	bne _081A9B2E
	cmp r6, #1
	bne _081A9B26
	mov r0, sl
	cmp r0, #1
	bne _081A9B48
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _081A9B5A
	b _081A9C1A
_081A9B26:
	cmp r6, #3
	bne _081A9C1A
	mov r4, sl
	b _081A9B54
_081A9B2E:
	ldr r0, [sp, #0x3c]
	cmp r0, #2
	bne _081A9B5A
	cmp r6, #0
	bne _081A9B4E
	mov r3, sl
	cmp r3, #2
	bne _081A9B48
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r1, r4
	beq _081A9B5A
	b _081A9C1A
_081A9B48:
	cmp r1, #0
	beq _081A9B5A
	b _081A9C1A
_081A9B4E:
	cmp r6, #2
	bne _081A9C1A
	mov r0, sl
_081A9B54:
	ldr r0, _081A9B70 @ =0xFFFFFF00
	cmp r1, r0
	bne _081A9C1A
_081A9B5A:
	mov r3, sl
	cmp r3, #1
	bne _081A9B8A
	cmp r6, #1
	bne _081A9B7E
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	bne _081A9B74
	movs r0, #0x80
	lsls r0, r0, #1
	b _081A9BB6
	.align 2, 0
_081A9B70: .4byte 0xFFFFFF00
_081A9B74:
	movs r3, #0x80
	lsls r3, r3, #1
	cmp r1, r3
	beq _081A9BC4
	b _081A9C1A
_081A9B7E:
	cmp r6, #3
	bne _081A9C1A
	ldr r4, [sp, #0x3c]
	cmp r4, #1
	beq _081A9BB4
	b _081A9BC0
_081A9B8A:
	mov r0, sl
	cmp r0, #2
	bne _081A9BD0
	cmp r6, #0
	bne _081A9BAA
	ldr r3, [sp, #0x3c]
	cmp r3, #2
	bne _081A9BA4
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r1, r4
	beq _081A9BC4
	b _081A9C1A
_081A9BA4:
	movs r0, #0x80
	lsls r0, r0, #1
	b _081A9BB6
_081A9BAA:
	cmp r6, #2
	bne _081A9C1A
	ldr r3, [sp, #0x3c]
	cmp r3, #2
	bne _081A9BC0
_081A9BB4:
	ldr r0, _081A9BBC @ =0xFFFFFF00
_081A9BB6:
	cmp r1, r0
	beq _081A9BC4
	b _081A9C1A
	.align 2, 0
_081A9BBC: .4byte 0xFFFFFF00
_081A9BC0:
	cmp r1, #0
	bne _081A9C1A
_081A9BC4:
	mov r4, sl
	cmp r4, #2
	bne _081A9BD0
	ldr r0, [sp, #0x3c]
	cmp r0, #2
	beq _081A9BDC
_081A9BD0:
	mov r1, sl
	cmp r1, #1
	bne _081A9BEE
	ldr r3, [sp, #0x3c]
	cmp r3, #1
	bne _081A9BEE
_081A9BDC:
	adds r0, r2, #0
	cmp r2, #0
	bge _081A9BE4
	rsbs r0, r2, #0
_081A9BE4:
	movs r4, #0x80
	lsls r4, r4, #1
	cmp r0, r4
	ble _081A9BFE
	b _081A9C1A
_081A9BEE:
	adds r0, r2, #0
	cmp r0, #0
	bge _081A9BF6
	rsbs r0, r0, #0
_081A9BF6:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _081A9C00
_081A9BFE:
	adds r5, r7, #0
_081A9C00:
	cmp r5, #0
	blt _081A9C1A
	ldr r0, [sp, #0x2c]
	cmp r6, r0
	bne _081A9C0E
	str r5, [sp, #0x38]
	b _081A9C1A
_081A9C0E:
	ldr r1, [sp, #0x34]
	lsls r0, r1, #2
	add r0, sp
	str r5, [r0]
	adds r1, #1
	str r1, [sp, #0x34]
_081A9C1A:
	adds r6, #1
	movs r0, #3
	ands r6, r0
	ldr r2, [sp, #0x30]
	subs r2, #1
	str r2, [sp, #0x30]
	cmp r2, #0
	blt _081A9C2C
	b _081A9864
_081A9C2C:
	ldr r3, [sp, #0x34]
	cmp r3, #0
	bne _081A9C34
	b _081A9D8C
_081A9C34:
	movs r4, #0
	str r4, [sp, #0x30]
	ldr r4, [sp, #0x28]
	adds r4, #0xc
	ldr r0, [sp, #0x30]
	cmp r0, r3
	bge _081A9CE2
	mov r6, sp
_081A9C44:
	ldr r1, [r6]
	ldr r0, [sp, #0x20]
	bl FUN_081ac0bc
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081A9CD4
	mov sb, r4
	ldr r5, [r6]
	ldr r7, _081A9C90 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x28]
	strh r4, [r0, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9C94
	adds r0, #4
	b _081A9C9E
	.align 2, 0
_081A9C90: .4byte 0x030046A4
_081A9C94:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9C9E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sb
	strh r0, [r1, #2]
	mov r2, r8
	lsls r0, r2, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r1, [r6]
	ldr r0, [sp, #0x20]
	bl FUN_081ac0e8
	ldr r3, [sp, #0x24]
	ldr r4, _081A9CCC @ =0x00000CB8
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, _081A9CD0 @ =0x00000CB4
	adds r1, r3, r0
	b _081AA218
	.align 2, 0
_081A9CCC: .4byte 0x00000CB8
_081A9CD0: .4byte 0x00000CB4
_081A9CD4:
	adds r6, #4
	ldr r1, [sp, #0x30]
	adds r1, #1
	str r1, [sp, #0x30]
	ldr r2, [sp, #0x34]
	cmp r1, r2
	blt _081A9C44
_081A9CE2:
	ldr r2, _081A9D40 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081A9D44 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081A9D48 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r1, [sp, #0x34]
	bl Mod
	str r0, [sp, #0x30]
	lsls r0, r0, #2
	add r0, sp
	mov r8, r4
	ldr r5, [r0]
	ldr r6, _081A9D4C @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r3, [sp, #0x28]
	strh r4, [r3, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9D50
	adds r0, #4
	b _081A9D5A
	.align 2, 0
_081A9D40: .4byte 0x030046B8
_081A9D44: .4byte 0x000003FF
_081A9D48: .4byte 0x0203B400
_081A9D4C: .4byte 0x030046A4
_081A9D50:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9D5A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, r8
	strh r0, [r4, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r1, [sp, #0x30]
	lsls r0, r1, #2
	add r0, sp
	ldr r1, [r0]
	ldr r0, [sp, #0x20]
	bl FUN_081ac0e8
	ldr r2, [sp, #0x24]
	ldr r3, _081A9D88 @ =0x00000CB8
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #1
	b _081AA212
	.align 2, 0
_081A9D88: .4byte 0x00000CB8
_081A9D8C:
	movs r0, #1
	rsbs r0, r0, #0
	ldr r1, [sp, #0x38]
	cmp r1, r0
	beq _081A9E24
	ldr r0, [sp, #0x20]
	bl FUN_081ac0bc
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081A9E24
	ldr r7, [sp, #0x28]
	adds r7, #0xc
	ldr r5, _081A9DE0 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	ldr r0, [sp, #0x38]
	bl Mod
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	ldr r0, [sp, #0x38]
	bl Div
	adds r6, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x28]
	strh r4, [r0, #0xc]
	ldr r0, [sp, #0x38]
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9DE4
	adds r0, #4
	b _081A9DF0
	.align 2, 0
_081A9DE0: .4byte 0x030046A4
_081A9DE4:
	ldr r0, [r5]
	ldr r2, [sp, #0x38]
	lsls r1, r2, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9DF0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r7, #2]
	lsls r0, r6, #8
	adds r0, #0x80
	strh r0, [r7, #4]
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x38]
	bl FUN_081ac0e8
	ldr r3, [sp, #0x24]
	ldr r4, _081A9E1C @ =0x00000CB8
	adds r1, r3, r4
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	ldr r0, _081A9E20 @ =0x00000CB4
	adds r1, r3, r0
	b _081AA218
	.align 2, 0
_081A9E1C: .4byte 0x00000CB8
_081A9E20: .4byte 0x00000CB4
_081A9E24:
	ldr r1, [sp, #0x24]
	ldr r2, _081A9E40 @ =0x00000CB9
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r6, r0, #2
	movs r0, #3
	ands r6, r0
	cmp r6, #1
	beq _081A9E60
	cmp r6, #1
	bgt _081A9E44
	cmp r6, #0
	beq _081A9E4E
	b _081A9EB4
	.align 2, 0
_081A9E40: .4byte 0x00000CB9
_081A9E44:
	cmp r6, #2
	beq _081A9E80
	cmp r6, #3
	beq _081A9E94
	b _081A9EB4
_081A9E4E:
	ldr r3, [sp, #0x20]
	ldr r4, _081A9E5C @ =0x00000256
	adds r1, r3, r4
	ldrh r0, [r1]
	adds r7, r0, #1
	str r1, [sp, #0x58]
	b _081A9EBE
	.align 2, 0
_081A9E5C: .4byte 0x00000256
_081A9E60:
	ldr r0, [sp, #0x20]
	ldr r2, _081A9E78 @ =0x00000256
	adds r1, r0, r2
	ldr r0, _081A9E7C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldrh r4, [r1]
	adds r7, r0, r4
	str r1, [sp, #0x58]
	b _081A9EBE
	.align 2, 0
_081A9E78: .4byte 0x00000256
_081A9E7C: .4byte 0x030046A4
_081A9E80:
	ldr r0, [sp, #0x20]
	ldr r2, _081A9E90 @ =0x00000256
	adds r1, r0, r2
	ldrh r0, [r1]
	subs r7, r0, #1
	str r1, [sp, #0x58]
	b _081A9EBE
	.align 2, 0
_081A9E90: .4byte 0x00000256
_081A9E94:
	ldr r3, [sp, #0x20]
	ldr r4, _081A9EAC @ =0x00000256
	adds r1, r3, r4
	ldrh r2, [r1]
	ldr r0, _081A9EB0 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	subs r7, r2, r0
	str r1, [sp, #0x58]
	b _081A9EBE
	.align 2, 0
_081A9EAC: .4byte 0x00000256
_081A9EB0: .4byte 0x030046A4
_081A9EB4:
	ldr r4, [sp, #0x20]
	ldr r1, _081A9ED0 @ =0x00000256
	adds r0, r4, r1
	ldrh r7, [r0]
	str r0, [sp, #0x58]
_081A9EBE:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9ED4
	adds r0, #4
	b _081A9EE0
	.align 2, 0
_081A9ED0: .4byte 0x00000256
_081A9ED4:
	ldr r0, _081A9EFC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A9EE0:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sl, r0
	ldr r2, [sp, #0x58]
	ldrh r4, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9F00
	adds r0, #4
	b _081A9F0C
	.align 2, 0
_081A9EFC: .4byte 0x030046A4
_081A9F00:
	ldr r0, _081A9F24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A9F0C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	mov sb, r0
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9F28
	adds r0, #4
	b _081A9F34
	.align 2, 0
_081A9F24: .4byte 0x030046A4
_081A9F28:
	ldr r0, _081A9F78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A9F34:
	ldrh r0, [r0, #2]
	str r0, [sp, #0x48]
	add r5, sp, #0x18
	ldr r3, _081A9F78 @ =0x030046A4
	mov r8, r3
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r7, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r7, #0
	bl Div
	str r0, [sp, #0x4c]
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r5]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9F7C
	adds r0, #4
	b _081A9F88
	.align 2, 0
_081A9F78: .4byte 0x030046A4
_081A9F7C:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r7, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081A9F88:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r5, #2]
	ldr r4, [sp, #0x4c]
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r5, #4]
	add r4, sp, #0x18
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081A9FAC
	adds r0, #4
	b _081A9FB8
_081A9FAC:
	ldr r2, _081A9FCC @ =0x030046A4
	ldr r1, [r2]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081A9FB8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081A9FD0
	cmp r2, #2
	beq _081A9FD4
	b _081A9FD8
	.align 2, 0
_081A9FCC: .4byte 0x030046A4
_081A9FD0:
	ldrb r0, [r4, #4]
	b _081A9FD6
_081A9FD4:
	ldrb r0, [r4]
_081A9FD6:
	subs r1, r1, r0
_081A9FD8:
	str r1, [sp, #0x50]
	ldr r0, [sp, #0x58]
	ldrh r5, [r0]
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x54]
	ldr r2, _081AA020 @ =0x030046A4
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r1, _081AA020 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	add r0, sp, #0x18
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081AA024
	adds r0, #4
	b _081AA030
	.align 2, 0
_081AA020: .4byte 0x030046A4
_081AA024:
	ldr r3, _081AA05C @ =0x030046A4
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081AA030:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	ldr r4, [sp, #0x54]
	strh r1, [r4, #2]
	mov r1, r8
	lsls r0, r1, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r2, [sp, #0x58]
	ldrh r4, [r2]
	add r5, sp, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081AA060
	adds r0, #4
	b _081AA06C
	.align 2, 0
_081AA05C: .4byte 0x030046A4
_081AA060:
	ldr r0, _081AA080 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AA06C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081AA084
	cmp r2, #2
	beq _081AA088
	b _081AA08C
	.align 2, 0
_081AA080: .4byte 0x030046A4
_081AA084:
	ldrb r0, [r5, #4]
	b _081AA08A
_081AA088:
	ldrb r0, [r5]
_081AA08A:
	subs r1, r1, r0
_081AA08C:
	ldr r3, [sp, #0x50]
	subs r2, r3, r1
	adds r0, r1, #0
	adds r0, #0xff
	asrs r0, r0, #8
	adds r1, r3, #0
	adds r1, #0xff
	asrs r1, r1, #8
	subs r0, r0, r1
	lsls r1, r0, #8
	movs r0, #0x43
	ldr r4, [sp, #0x48]
	ands r4, r0
	cmp r4, #0
	beq _081AA0AC
	b _081AA228
_081AA0AC:
	cmp r2, #0
	beq _081AA19A
	mov r0, sl
	cmp r0, #1
	bne _081AA0CE
	cmp r6, #1
	bne _081AA0C6
	mov r3, sb
	cmp r3, #1
	bne _081AA0E4
	movs r0, #0x80
	lsls r0, r0, #1
	b _081AA0F4
_081AA0C6:
	cmp r6, #3
	beq _081AA0CC
	b _081AA228
_081AA0CC:
	b _081AA0F0
_081AA0CE:
	mov r0, sl
	cmp r0, #2
	bne _081AA0FA
	cmp r6, #0
	bne _081AA0EA
	mov r3, sb
	cmp r3, #2
	bne _081AA0E4
	movs r0, #0x80
	lsls r0, r0, #1
	b _081AA0F4
_081AA0E4:
	cmp r1, #0
	beq _081AA0FA
	b _081AA228
_081AA0EA:
	cmp r6, #2
	beq _081AA0F0
	b _081AA228
_081AA0F0:
	mov r4, sb
	ldr r0, _081AA110 @ =0xFFFFFF00
_081AA0F4:
	cmp r1, r0
	beq _081AA0FA
	b _081AA228
_081AA0FA:
	mov r0, sb
	cmp r0, #1
	bne _081AA128
	cmp r6, #1
	bne _081AA11A
	mov r3, sl
	cmp r3, #1
	bne _081AA114
	movs r0, #0x80
	lsls r0, r0, #1
	b _081AA150
	.align 2, 0
_081AA110: .4byte 0xFFFFFF00
_081AA114:
	movs r0, #0x80
	lsls r0, r0, #1
	b _081AA150
_081AA11A:
	cmp r6, #3
	beq _081AA120
	b _081AA228
_081AA120:
	mov r4, sl
	cmp r4, #1
	beq _081AA14E
	b _081AA15C
_081AA128:
	mov r0, sb
	cmp r0, #2
	bne _081AA16C
	cmp r6, #0
	bne _081AA144
	mov r3, sl
	cmp r3, #2
	bne _081AA13E
	movs r0, #0x80
	lsls r0, r0, #1
	b _081AA150
_081AA13E:
	movs r0, #0x80
	lsls r0, r0, #1
	b _081AA150
_081AA144:
	cmp r6, #2
	bne _081AA228
	mov r4, sl
	cmp r4, #2
	bne _081AA15C
_081AA14E:
	ldr r0, _081AA158 @ =0xFFFFFF00
_081AA150:
	cmp r1, r0
	beq _081AA160
	b _081AA228
	.align 2, 0
_081AA158: .4byte 0xFFFFFF00
_081AA15C:
	cmp r1, #0
	bne _081AA228
_081AA160:
	mov r0, sb
	cmp r0, #2
	bne _081AA16C
	mov r1, sl
	cmp r1, #2
	beq _081AA178
_081AA16C:
	mov r3, sb
	cmp r3, #1
	bne _081AA18A
	mov r4, sl
	cmp r4, #1
	bne _081AA18A
_081AA178:
	adds r1, r2, #0
	cmp r2, #0
	bge _081AA180
	rsbs r1, r2, #0
_081AA180:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	ble _081AA19A
	b _081AA228
_081AA18A:
	adds r0, r2, #0
	cmp r0, #0
	bge _081AA192
	rsbs r0, r0, #0
_081AA192:
	movs r5, #1
	rsbs r5, r5, #0
	cmp r0, #0xff
	bgt _081AA19C
_081AA19A:
	adds r5, r7, #0
_081AA19C:
	cmp r5, #0
	blt _081AA228
	ldr r0, [sp, #0x28]
	adds r0, #0xc
	mov r8, r0
	ldr r6, _081AA1E0 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	adds r7, r0, #0
	lsls r4, r4, #8
	adds r4, #0x80
	ldr r0, [sp, #0x28]
	strh r4, [r0, #0xc]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081AA1E4
	adds r0, #4
	b _081AA1EE
	.align 2, 0
_081AA1E0: .4byte 0x030046A4
_081AA1E4:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081AA1EE:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, r8
	strh r0, [r1, #2]
	lsls r0, r7, #8
	adds r0, #0x80
	strh r0, [r1, #4]
	ldr r0, [sp, #0x20]
	adds r1, r5, #0
	bl FUN_081ac0e8
	ldr r2, [sp, #0x24]
	ldr r3, _081AA220 @ =0x00000CB8
	adds r1, r2, r3
	ldrb r0, [r1]
	adds r0, #2
_081AA212:
	strb r0, [r1]
	ldr r4, _081AA224 @ =0x00000CB4
	adds r1, r2, r4
_081AA218:
	movs r0, #0x28
	strh r0, [r1]
	b _081AA238
	.align 2, 0
_081AA220: .4byte 0x00000CB8
_081AA224: .4byte 0x00000CB4
_081AA228:
	ldr r1, [sp, #0x24]
	ldr r2, _081AA248 @ =0x00000CB9
	adds r0, r1, r2
	ldrb r1, [r0]
	adds r1, #1
	movs r2, #3
	ands r1, r2
	strb r1, [r0]
_081AA238:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AA248: .4byte 0x00000CB9

	thumb_func_start FUN_081aa24c
FUN_081aa24c: @ 0x081AA24C
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	ldr r0, _081AA268 @ =0x00000CA3
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AA26C
	subs r0, #1
	strb r0, [r1]
	b _081AA2AA
	.align 2, 0
_081AA268: .4byte 0x00000CA3
_081AA26C:
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, _081AA2B0 @ =0x00000CAA
	adds r4, r5, r1
	movs r0, #0
	ldrsh r1, [r4, r0]
	subs r1, #1
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	movs r2, #0xd0
	muls r2, r0, r2
	adds r2, r2, r5
	ldr r0, _081AA2B4 @ =0x00000674
	adds r2, r2, r0
	adds r0, r5, #0
	bl FUN_081aa90c
	ldrh r1, [r4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x11
	ldr r0, _081AA2B4 @ =0x00000674
	adds r2, r5, r0
	adds r0, r5, #0
	bl FUN_081aa90c
	adds r0, r5, #0
	movs r1, #0
	adds r2, r6, #0
	bl FUN_081aa90c
_081AA2AA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081AA2B0: .4byte 0x00000CAA
_081AA2B4: .4byte 0x00000674

	thumb_func_start FUN_081aa2b8
FUN_081aa2b8: @ 0x081AA2B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _081AA3A0 @ =0x00000CAA
	adds r4, r7, r2
	movs r0, #6
	strh r0, [r4]
	movs r1, #6
	adds r2, #0x10
	adds r0, r7, r2
	strb r1, [r0]
	ldr r0, _081AA3A4 @ =0x00000CBC
	adds r1, r7, r0
	ldr r0, _081AA3A8 @ =0x7FFFFFFF
	str r0, [r1]
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0
	ldrsh r1, [r4, r2]
	adds r1, #1
	bl Div
	ldr r2, _081AA3AC @ =0x00000CBB
	adds r1, r7, r2
	strb r0, [r1]
	movs r0, #0
	mov sb, r0
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r8, r0
	blt _081AA316
	b _081AA438
_081AA316:
	movs r2, #0
	mov sl, r2
_081AA31A:
	movs r0, #0xd0
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r0, r2
	adds r5, r7, r0
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, [sp, #0xc]
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r4, #0
	ldr r1, _081AA3B0 @ =0x000001A5
	bl FUN_0822b20c
	adds r4, #0x80
	mov r0, sp
	ldrb r0, [r0, #0x14]
	strb r0, [r4]
	ldr r2, [sp, #0x10]
	lsls r1, r2, #0x10
	ldr r0, _081AA3B4 @ =0x0000922E
	lsrs r1, r1, #0x10
	bl GetFile
	adds r6, r5, #0
	adds r6, #0xa8
	str r0, [r6]
	ldrb r0, [r4]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_081a9774
	adds r0, r5, #0
	adds r0, #0xcc
	str r7, [r0]
	ldr r1, _081AA3A0 @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	subs r0, r1, #1
	cmp r8, r0
	bne _081AA3B8
	adds r0, r5, #0
	adds r0, #0x98
	ldr r1, [r6]
	movs r2, #0
	str r2, [sp]
	movs r2, #0xf
	movs r3, #0
	bl FUN_08236fac
	movs r1, #0xe
	adds r2, r5, #0
	adds r2, #0xad
	ldrb r0, [r2]
	orrs r1, r0
	strb r1, [r2]
	b _081AA40C
	.align 2, 0
_081AA3A0: .4byte 0x00000CAA
_081AA3A4: .4byte 0x00000CBC
_081AA3A8: .4byte 0x7FFFFFFF
_081AA3AC: .4byte 0x00000CBB
_081AA3B0: .4byte 0x000001A5
_081AA3B4: .4byte 0x0000922E
_081AA3B8:
	subs r0, r1, #2
	cmp r8, r0
	bge _081AA3EE
	adds r0, r5, #0
	adds r0, #0xb2
	mov r1, sl
	strb r1, [r0]
	movs r1, #0x12
	adds r2, r5, #0
	adds r2, #0xad
	ldrb r0, [r2]
	orrs r1, r0
	strb r1, [r2]
	adds r0, r5, #0
	adds r0, #0x98
	ldr r1, [r6]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r2, [sp, #8]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0xe
	bl FUN_08236fac
	b _081AA40C
_081AA3EE:
	movs r1, #0xa
	adds r2, r5, #0
	adds r2, #0xad
	ldrb r0, [r2]
	orrs r1, r0
	strb r1, [r2]
	adds r0, r5, #0
	adds r0, #0x98
	ldr r1, [r6]
	movs r2, #0
	str r2, [sp]
	movs r2, #0xf
	movs r3, #0
	bl FUN_08236fac
_081AA40C:
	adds r0, r5, #0
	adds r0, #0xa0
	mov r1, sb
	strh r1, [r0]
	movs r2, #1
	add sb, r2
	mov r0, sb
	cmp r0, #8
	ble _081AA422
	movs r1, #0
	mov sb, r1
_081AA422:
	movs r2, #0x18
	add sl, r2
	movs r0, #1
	add r8, r0
	ldr r1, _081AA448 @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	bge _081AA438
	b _081AA31A
_081AA438:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AA448: .4byte 0x00000CAA

	thumb_func_start FUN_081aa44c
FUN_081aa44c: @ 0x081AA44C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r1, #0
	str r1, [sp]
	ldr r2, _081AA490 @ =0x00000CAA
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	blt _081AA470
	b _081AA58A
_081AA470:
	movs r2, #0
	mov sl, r2
	ldr r0, _081AA494 @ =0x00000674
	adds r6, r7, r0
	ldr r1, _081AA498 @ =0x00000705
	adds r1, r1, r7
	mov sb, r1
_081AA47E:
	movs r1, #1
	mov r2, sb
	ldrb r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081AA49C
	movs r0, #1
	b _081AA49E
	.align 2, 0
_081AA490: .4byte 0x00000CAA
_081AA494: .4byte 0x00000674
_081AA498: .4byte 0x00000705
_081AA49C:
	movs r0, #0
_081AA49E:
	cmp r0, #0
	bne _081AA56C
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081AA4C6
	cmp r1, #0
	blt _081AA4C6
	ldr r0, _081AA4CC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081AA4C6
	ldr r0, _081AA4D0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081AA4D4
_081AA4C6:
	movs r4, #0
	b _081AA4E2
	.align 2, 0
_081AA4CC: .4byte 0x030046A8
_081AA4D0: .4byte 0x030046AC
_081AA4D4:
	ldr r0, _081AA4F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081AA4E2:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081AA4F8
	adds r0, #4
	b _081AA504
	.align 2, 0
_081AA4F4: .4byte 0x030046A4
_081AA4F8:
	ldr r0, _081AA518 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AA504:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081AA51C
	cmp r2, #2
	beq _081AA520
	b _081AA524
	.align 2, 0
_081AA518: .4byte 0x030046A4
_081AA51C:
	ldrb r0, [r5, #4]
	b _081AA522
_081AA520:
	ldrb r0, [r5]
_081AA522:
	subs r1, r1, r0
_081AA524:
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, r1
	bge _081AA54C
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r1, sl
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	bne _081AA546
	orrs r1, r3
	str r1, [r2]
_081AA546:
	movs r2, #1
	rsbs r2, r2, #0
	b _081AA56A
_081AA54C:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r1, sl
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081AA568
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
_081AA568:
	movs r2, #1
_081AA56A:
	add r8, r2
_081AA56C:
	movs r0, #0xd0
	add sl, r0
	adds r6, #0xd0
	add sb, r0
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	ldr r2, _081AA59C @ =0x00000CAA
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r2, [sp]
	cmp r2, r0
	bge _081AA58A
	b _081AA47E
_081AA58A:
	ldr r1, _081AA59C @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	blt _081AA5A0
	movs r0, #1
	b _081AA5AE
	.align 2, 0
_081AA59C: .4byte 0x00000CAA
_081AA5A0:
	mov r1, r8
	cmn r1, r0
	ble _081AA5AA
	movs r0, #0
	b _081AA5AE
_081AA5AA:
	movs r0, #1
	rsbs r0, r0, #0
_081AA5AE:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081aa5c0
FUN_081aa5c0: @ 0x081AA5C0
	push {r4, r5, r6, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _081AA5EC @ =0x00000CAA
	adds r2, r1, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r3, r0
	bge _081AA60E
	movs r4, #1
	adds r5, r2, #0
	ldr r6, _081AA5F0 @ =0x00000705
	adds r2, r1, r6
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
_081AA5E0:
	ldrb r0, [r2]
	ands r0, r4
	cmp r0, #0
	beq _081AA5F4
	movs r0, #1
	b _081AA5F6
	.align 2, 0
_081AA5EC: .4byte 0x00000CAA
_081AA5F0: .4byte 0x00000705
_081AA5F4:
	movs r0, #0
_081AA5F6:
	cmp r0, #0
	bne _081AA600
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
_081AA600:
	adds r2, #0xd0
	adds r1, #0xd0
	adds r3, #1
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r3, r0
	blt _081AA5E0
_081AA60E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081aa614
FUN_081aa614: @ 0x081AA614
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _081AA674 @ =0x00000482
	adds r1, r7, r0
	ldrh r0, [r1]
	movs r2, #1
	mov sl, r2
	cmp r0, #0
	beq _081AA634
	adds r1, r0, #0
	mov sl, r1
_081AA634:
	movs r3, #0
	mov r8, r3
	ldr r4, _081AA678 @ =0x00000CAA
	adds r0, r7, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	blt _081AA646
	b _081AA7F2
_081AA646:
	movs r2, #1
	mov sb, r2
_081AA64A:
	movs r0, #0xd0
	mov r4, r8
	muls r4, r0, r4
	adds r4, r7, r4
	ldr r3, _081AA67C @ =0x00000704
	adds r0, r4, r3
	ldrb r0, [r0]
	add r1, sp, #4
	add r2, sp, #8
	bl FUN_081a9774
	movs r1, #0x10
	ldr r0, _081AA680 @ =0x00000705
	adds r4, r4, r0
	ldrb r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081AA684
	movs r0, #1
	b _081AA686
	.align 2, 0
_081AA674: .4byte 0x00000482
_081AA678: .4byte 0x00000CAA
_081AA67C: .4byte 0x00000704
_081AA680: .4byte 0x00000705
_081AA684:
	movs r0, #0
_081AA686:
	adds r3, r0, #0
	cmp r3, #0
	beq _081AA6BA
	movs r0, #0xd0
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, r7
	movs r1, #0xde
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r3, #0xe0
	lsls r3, r3, #3
	adds r1, r7, r3
	adds r1, r1, r2
	ldr r1, [r1]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r2, [sp, #8]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0xe
	bl FUN_08236fac
	b _081AA6E0
_081AA6BA:
	movs r0, #0xd0
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, r7
	movs r4, #0xde
	lsls r4, r4, #3
	adds r0, r0, r4
	adds r4, #0x10
	adds r1, r7, r4
	adds r1, r1, r2
	ldr r1, [r1]
	movs r4, #0xa0
	lsls r4, r4, #3
	adds r2, r7, r4
	ldrb r2, [r2]
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
_081AA6E0:
	movs r0, #0xd0
	mov r5, r8
	muls r5, r0, r5
	movs r6, #0xcb
	lsls r6, r6, #3
	adds r4, r5, r6
	adds r4, r7, r4
	adds r4, #0x98
	movs r0, #0x40
	mov r1, sl
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	adds r4, r5, r7
	adds r4, r4, r6
	adds r5, r5, r7
	movs r0, #0xde
	lsls r0, r0, #3
	adds r5, r5, r0
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r4, #0x10]
	ldrb r0, [r5, #4]
	mov r2, sb
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, sb
	ands r0, r1
	cmp r2, r0
	beq _081AA73C
	ldr r0, [r4]
	movs r1, #4
	orrs r0, r1
	b _081AA744
_081AA73C:
	ldr r0, [r4]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081AA744:
	str r0, [r4]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081AA768
	ldr r0, [r4]
	movs r1, #8
	orrs r0, r1
	b _081AA770
_081AA768:
	ldr r0, [r4]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081AA770:
	str r0, [r4]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #0xe]
	ldr r3, _081AA7A8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r5, #7]
	cmp r0, r4
	blo _081AA7E0
	strh r1, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081AA7AC
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081AA7A0
	ldrb r0, [r5, #5]
_081AA7A0:
	subs r0, #1
	strh r0, [r5, #8]
	b _081AA7BC
	.align 2, 0
_081AA7A8: .4byte 0x0000FFFF
_081AA7AC:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081AA7BC
	strh r1, [r5, #8]
_081AA7BC:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081AA7E0
	mov r3, sb
	strb r3, [r5, #7]
_081AA7E0:
	movs r4, #1
	add r8, r4
	ldr r1, _081AA804 @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	bge _081AA7F2
	b _081AA64A
_081AA7F2:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AA804: .4byte 0x00000CAA

	thumb_func_start FUN_081aa808
FUN_081aa808: @ 0x081AA808
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r6, #0
	ldr r2, _081AA848 @ =0x00000CAA
	adds r0, r7, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _081AA874
	movs r0, #1
	mov sb, r0
	adds r5, r1, #0
	ldr r1, _081AA84C @ =0x00000705
	adds r4, r7, r1
_081AA838:
	ldrb r0, [r4]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _081AA850
	movs r0, #1
	b _081AA852
	.align 2, 0
_081AA848: .4byte 0x00000CAA
_081AA84C: .4byte 0x00000705
_081AA850:
	movs r0, #0
_081AA852:
	cmp r0, #0
	bne _081AA862
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
_081AA862:
	adds r5, #0xd0
	adds r4, #0xd0
	adds r6, #1
	ldr r1, _081AA880 @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _081AA838
_081AA874:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AA880: .4byte 0x00000CAA

	thumb_func_start FUN_081aa884
FUN_081aa884: @ 0x081AA884
	push {r4, r5, r6, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _081AA8B0 @ =0x00000CAA
	adds r2, r1, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r3, r0
	bge _081AA8CE
	movs r4, #1
	adds r5, r2, #0
	ldr r6, _081AA8B4 @ =0x00000705
	adds r2, r1, r6
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
_081AA8A4:
	ldrb r0, [r2]
	ands r0, r4
	cmp r0, #0
	beq _081AA8B8
	movs r0, #1
	b _081AA8BA
	.align 2, 0
_081AA8B0: .4byte 0x00000CAA
_081AA8B4: .4byte 0x00000705
_081AA8B8:
	movs r0, #0
_081AA8BA:
	cmp r0, #0
	beq _081AA8C0
	str r4, [r1]
_081AA8C0:
	adds r2, #0xd0
	adds r1, #0xd0
	adds r3, #1
	movs r6, #0
	ldrsh r0, [r5, r6]
	cmp r3, r0
	blt _081AA8A4
_081AA8CE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081aa8d4
FUN_081aa8d4: @ 0x081AA8D4
	push {r4, r5, r6, lr}
	adds r1, r0, #0
	movs r5, #0
	ldr r2, _081AA908 @ =0x00000CAA
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r5, r0
	bge _081AA902
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r4, r1, r0
	ldr r2, _081AA908 @ =0x00000CAA
	adds r6, r1, r2
_081AA8F0:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0xd0
	adds r5, #1
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r5, r0
	blt _081AA8F0
_081AA902:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081AA908: .4byte 0x00000CAA

	thumb_func_start FUN_081aa90c
FUN_081aa90c: @ 0x081AA90C
	movs r3, #0xd0
	muls r1, r3, r1
	adds r0, r0, r1
	ldr r1, _081AA920 @ =0x00000674
	adds r0, r0, r1
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r0]
	str r2, [r0, #4]
	bx lr
	.align 2, 0
_081AA920: .4byte 0x00000674

	thumb_func_start FUN_081aa924
FUN_081aa924: @ 0x081AA924
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r3, [r1]
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r2, #0
	ldr r7, _081AA96C @ =0x00000CAA
	adds r0, r3, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	bge _081AA9C8
	mov r5, sp
	add r7, sp, #8
	mov sb, r7
	ldr r0, _081AA970 @ =0x00000674
	adds r4, r3, r0
	ldr r1, _081AA974 @ =0x00000704
	adds r6, r3, r1
	movs r7, #1
	mov r8, r7
_081AA95E:
	ldrb r0, [r6, #1]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _081AA978
	movs r0, #1
	b _081AA97A
	.align 2, 0
_081AA96C: .4byte 0x00000CAA
_081AA970: .4byte 0x00000674
_081AA974: .4byte 0x00000704
_081AA978:
	movs r0, #0
_081AA97A:
	cmp r0, #0
	bne _081AA9B6
	mov r7, sb
	ldrh r0, [r7]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r7, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r7, #4
	ldrsh r1, [r5, r7]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	bl FUN_0823785c
	strb r0, [r6]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r3, [sp, #0x14]
	ldr r2, [sp, #0x10]
_081AA9B6:
	adds r4, #0xd0
	adds r6, #0xd0
	adds r2, #1
	ldr r1, _081AA9D8 @ =0x00000CAA
	adds r0, r3, r1
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r2, r0
	blt _081AA95E
_081AA9C8:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AA9D8: .4byte 0x00000CAA

	thumb_func_start FUN_081aa9dc
FUN_081aa9dc: @ 0x081AA9DC
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _081AA9F8 @ =0x00000CA8
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	ldr r0, _081AA9FC @ =0x00000CA4
	adds r1, r1, r0
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_081AA9F8: .4byte 0x00000CA8
_081AA9FC: .4byte 0x00000CA4

	thumb_func_start FUN_081aaa00
FUN_081aaa00: @ 0x081AAA00
	push {r4, r5, lr}
	adds r4, r2, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r3, _081AAA24 @ =0x00000CA8
	adds r0, r2, r3
	movs r5, #0
	ldrsh r3, [r0, r5]
	cmp r3, r1
	blt _081AAA2C
	strh r1, [r0]
	ldr r0, _081AAA28 @ =0x00000CA4
	adds r1, r2, r0
	movs r0, #0xff
	b _081AAA3A
	.align 2, 0
_081AAA24: .4byte 0x00000CA8
_081AAA28: .4byte 0x00000CA4
_081AAA2C:
	rsbs r1, r1, #0
	cmp r3, r1
	bgt _081AAA3C
	strh r1, [r0]
	ldr r3, _081AAA58 @ =0x00000CA4
	adds r1, r2, r3
	movs r0, #1
_081AAA3A:
	strb r0, [r1]
_081AAA3C:
	ldr r5, _081AAA5C @ =0x00000CA8
	adds r1, r2, r5
	ldr r3, _081AAA58 @ =0x00000CA4
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r4, r0
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081AAA58: .4byte 0x00000CA4
_081AAA5C: .4byte 0x00000CA8

	thumb_func_start FUN_081aaa60
FUN_081aaa60: @ 0x081AAA60
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _081AAA74 @ =0x00000C44
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_081AAA74: .4byte 0x00000C44

	thumb_func_start FUN_081aaa78
FUN_081aaa78: @ 0x081AAA78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r7, [r0]
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ldr r2, _081AAAD8 @ =0x00000C44
	adds r1, r7, r2
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _081AAB24
	ldr r0, [r4, #0x44]
	ldr r5, [r0, #0x1c]
	ldr r6, [r0, #0x20]
	movs r0, #0
	mov ip, r0
	ldr r2, _081AAADC @ =0x00000CAA
	adds r1, r7, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp ip, r0
	bge _081AAB24
	movs r0, #2
	mov sb, r0
	movs r2, #1
	mov r8, r2
	adds r3, r7, #0
	ldr r7, _081AAAE0 @ =0x00000705
	adds r4, r3, r7
	mov sl, r1
_081AAAC8:
	ldrb r0, [r4]
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	beq _081AAAE4
	movs r0, #1
	b _081AAAE6
	.align 2, 0
_081AAAD8: .4byte 0x00000C44
_081AAADC: .4byte 0x00000CAA
_081AAAE0: .4byte 0x00000705
_081AAAE4:
	movs r0, #0
_081AAAE6:
	cmp r0, #0
	beq _081AAB12
	ldrb r0, [r4]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _081AAAF8
	movs r0, #1
	b _081AAAFA
_081AAAF8:
	movs r0, #0
_081AAAFA:
	cmp r0, #0
	bne _081AAB12
	ldr r7, _081AAB34 @ =0x00000674
	adds r0, r3, r7
	ldr r1, [r0]
	ldr r2, [r0, #4]
	adds r7, #0xa0
	adds r0, r3, r7
	str r5, [r0]
	str r6, [r0, #4]
	adds r6, r2, #0
	adds r5, r1, #0
_081AAB12:
	adds r3, #0xd0
	adds r4, #0xd0
	movs r0, #1
	add ip, r0
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp ip, r0
	blt _081AAAC8
_081AAB24:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AAB34: .4byte 0x00000674

	thumb_func_start FUN_081aab38
FUN_081aab38: @ 0x081AAB38
	push {r4, r5, lr}
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #0xd0
	muls r0, r2, r0
	adds r0, r0, r3
	movs r1, #2
	ldr r5, _081AAB5C @ =0x00000705
	adds r0, r0, r5
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081AAB60
	movs r0, #1
	b _081AAB62
	.align 2, 0
_081AAB5C: .4byte 0x00000705
_081AAB60:
	movs r0, #0
_081AAB62:
	cmp r0, #0
	beq _081AAB9C
	movs r0, #0xd0
	muls r0, r2, r0
	adds r0, r0, r3
	movs r1, #1
	ldr r5, _081AAB80 @ =0x00000705
	adds r0, r0, r5
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081AAB84
	movs r0, #1
	b _081AAB86
	.align 2, 0
_081AAB80: .4byte 0x00000705
_081AAB84:
	movs r0, #0
_081AAB86:
	cmp r0, #0
	bne _081AAB9C
	movs r0, #0xd0
	muls r2, r0, r2
	adds r2, r3, r2
	ldr r0, _081AABA4 @ =0x0000071C
	adds r2, r2, r0
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
_081AAB9C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081AABA4: .4byte 0x0000071C

	thumb_func_start FUN_081aaba8
FUN_081aaba8: @ 0x081AABA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r1, #0
	mov sl, r2
	mov sb, r3
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r6, #0
	ldr r1, _081AABF8 @ =0x00000CAA
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _081AABD0
	b _081AACCA
_081AABD0:
	movs r0, #0xd0
	mov r8, r0
	ldr r1, _081AABFC @ =0x085B0A08
	mov ip, r1
	adds r4, r5, #0
	ldr r0, _081AAC00 @ =0x0000070A
	adds r3, r5, r0
_081AABDE:
	mov r0, r8
	muls r0, r6, r0
	adds r0, r0, r5
	ldr r1, _081AAC04 @ =0x00000705
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _081AAC08
	movs r0, #1
	b _081AAC0A
	.align 2, 0
_081AABF8: .4byte 0x00000CAA
_081AABFC: .4byte 0x085B0A08
_081AAC00: .4byte 0x0000070A
_081AAC04: .4byte 0x00000705
_081AAC08:
	movs r0, #0
_081AAC0A:
	cmp r0, #0
	beq _081AACB8
	mov r0, r8
	muls r0, r6, r0
	adds r0, r0, r5
	ldr r1, _081AAC28 @ =0x00000705
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081AAC2C
	movs r0, #1
	b _081AAC2E
	.align 2, 0
_081AAC28: .4byte 0x00000705
_081AAC2C:
	movs r0, #0
_081AAC2E:
	cmp r0, #0
	bne _081AACB8
	mov r0, sb
	cmp r0, #0
	bne _081AAC5C
	ldrb r0, [r3]
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _081AAC4C
	asrs r2, r0, #0xc
	b _081AAC52
_081AAC4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081AAC52:
	ldr r0, _081AAC58 @ =0x0000071E
	b _081AACAA
	.align 2, 0
_081AAC58: .4byte 0x0000071E
_081AAC5C:
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _081AAC76
	asrs r2, r0, #0xc
	b _081AAC7C
_081AAC76:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081AAC7C:
	ldr r0, _081AAC9C @ =0x0000071C
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _081AACA0
	asrs r2, r0, #0xc
	b _081AACA6
	.align 2, 0
_081AAC9C: .4byte 0x0000071C
_081AACA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081AACA6:
	movs r0, #0xe4
	lsls r0, r0, #3
_081AACAA:
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrb r0, [r3]
	add r0, sl
	strb r0, [r3]
_081AACB8:
	adds r4, #0xd0
	adds r3, #0xd0
	adds r6, #1
	ldr r1, _081AACD8 @ =0x00000CAA
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	blt _081AABDE
_081AACCA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AACD8: .4byte 0x00000CAA

	thumb_func_start FUN_081aacdc
FUN_081aacdc: @ 0x081AACDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r4, r3, #0
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [sp, #0x2c]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #3
	subs r1, r4, #1
	ldr r7, [sp, #0x68]
	subs r1, r7, r1
	bl Div
	str r0, [sp, #0x30]
	movs r0, #0
	mov sl, r4
	cmp sl, r7
	blt _081AAD1E
	b _081AAE78
_081AAD1E:
	mov r1, sp
	adds r1, #4
	str r1, [sp, #0x34]
	add r2, sp, #0xc
	mov sb, r2
	mov r3, sp
	adds r3, #0x14
	str r3, [sp, #0x38]
	add r4, sp, #0x1c
	mov r8, r4
	mov r7, sp
	adds r7, #0x24
	str r7, [sp, #0x40]
_081AAD38:
	adds r4, r0, #1
	ldr r0, [sp, #0x30]
	adds r5, r0, #0
	muls r5, r4, r5
	ldr r1, [sp, #0x38]
	ldrh r0, [r1]
	mov r2, sb
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r3, r8
	strh r0, [r3]
	ldr r7, [sp, #0x38]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	add r1, sp, #0x24
	ldr r2, _081AAD7C @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	muls r0, r5, r0
	str r4, [sp, #0x3c]
	cmp r0, #0
	blt _081AAD80
	asrs r0, r0, #0xa
	b _081AAD86
	.align 2, 0
_081AAD7C: .4byte 0x05000002
_081AAD80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_081AAD86:
	adds r3, r0, #0
	adds r0, r3, #0
	muls r0, r5, r0
	cmp r0, #0
	blt _081AAD94
	asrs r1, r0, #0xa
	b _081AAD9A
_081AAD94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081AAD9A:
	lsls r2, r1, #1
	lsls r0, r3, #1
	adds r6, r0, r3
	subs r0, r1, r0
	adds r0, r0, r5
	movs r4, #0
	adds r5, r0, #0
	muls r5, r4, r5
	subs r1, r1, r3
	mov ip, r1
	subs r0, r2, r6
	adds r0, #1
	ldr r7, [sp, #0x40]
	movs r3, #0
	ldrsh r1, [r7, r3]
	muls r0, r1, r0
	adds r7, r4, #0
	adds r4, r0, #0
	muls r4, r7, r4
	subs r1, r6, r2
	mov r3, r8
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _081AADD8
	asrs r1, r0, #0xa
	b _081AADDE
_081AADD8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081AADDE:
	mov r3, sb
	ldrh r0, [r3]
	adds r0, r0, r1
	ldr r4, [sp, #0x34]
	strh r0, [r4]
	subs r3, r2, r6
	adds r1, r3, #1
	ldr r7, [sp, #0x40]
	movs r4, #2
	ldrsh r0, [r7, r4]
	muls r0, r1, r0
	movs r7, #0
	adds r4, r0, #0
	muls r4, r7, r4
	rsbs r2, r2, #0
	adds r0, r2, r6
	str r0, [sp, #0x44]
	mov r1, r8
	movs r7, #2
	ldrsh r0, [r1, r7]
	ldr r1, [sp, #0x44]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _081AAE18
	asrs r1, r0, #0xa
	b _081AAE1E
_081AAE18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081AAE1E:
	mov r4, sb
	ldrh r0, [r4, #2]
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	strh r0, [r7, #2]
	adds r1, r3, #1
	ldr r3, [sp, #0x40]
	movs r4, #4
	ldrsh r0, [r3, r4]
	muls r0, r1, r0
	movs r7, #0
	adds r4, r0, #0
	muls r4, r7, r4
	adds r1, r2, r6
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, r0, r5
	add r0, ip
	cmp r0, #0
	blt _081AAE50
	asrs r1, r0, #0xa
	b _081AAE56
_081AAE50:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081AAE56:
	mov r4, sb
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	strh r0, [r7, #4]
	ldr r0, [sp, #0x2c]
	mov r1, sl
	ldr r2, [sp, #0x34]
	bl FUN_081aa90c
	ldr r0, [sp, #0x3c]
	movs r1, #1
	add sl, r1
	ldr r2, [sp, #0x68]
	cmp sl, r2
	bge _081AAE78
	b _081AAD38
_081AAE78:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081aae88
FUN_081aae88: @ 0x081AAE88
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #0x10]
	adds r7, r1, #0
	str r2, [sp, #0x14]
	str r3, [sp, #0x18]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	mov sb, r0
	movs r2, #0
	mov sl, r2
	ldr r0, _081AB014 @ =0x00000CAA
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp sl, r0
	bge _081AAF52
	mov r5, sp
	ldr r4, _081AB018 @ =0x00000674
	add r4, sb
	ldr r6, _081AB01C @ =0x00000716
	add r6, sb
	ldr r0, _081AB020 @ =0x00000714
	add r0, sb
	mov r8, r0
_081AAEC6:
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r6]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r6, #2]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r3, #0
	ldrsh r2, [r5, r3]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, [sp, #0x18]
	cmp r1, r0
	ble _081AAF3A
	cmp r7, #1
	bge _081AAF0C
	movs r7, #1
_081AAF0C:
	adds r0, r2, #0
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	movs r1, #2
	ldrsh r0, [r5, r1]
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #2]
	adds r1, r1, r0
	strh r1, [r4, #2]
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r1, r7, #0
	bl Div
	ldrh r1, [r4, #4]
	adds r1, r1, r0
	strh r1, [r4, #4]
_081AAF3A:
	adds r4, #0xd0
	adds r6, #0xd0
	movs r3, #0xd0
	add r8, r3
	movs r0, #1
	add sl, r0
	ldr r0, _081AB014 @ =0x00000CAA
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _081AAEC6
_081AAF52:
	ldr r2, [sp, #0x10]
	ldr r0, [r2, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r3, #0
	mov sl, r3
	ldr r0, _081AB014 @ =0x00000CAA
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	bge _081AAFFE
	mov r5, sp
	add r6, sp, #8
	ldr r4, _081AB018 @ =0x00000674
	add r4, sb
_081AAF76:
	ldrh r0, [r6]
	ldrh r1, [r4]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r6, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r3, #0
	ldrsh r2, [r5, r3]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #2
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r5, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r0, #0x90
	lsls r0, r0, #6
	cmp r1, r0
	ble _081AAFE4
	adds r0, r2, #0
	ldr r1, [sp, #0x14]
	bl Div
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	movs r1, #2
	ldrsh r0, [r5, r1]
	ldr r1, [sp, #0x14]
	bl Div
	ldrh r1, [r4, #2]
	adds r1, r1, r0
	strh r1, [r4, #2]
	movs r2, #4
	ldrsh r0, [r5, r2]
	ldr r1, [sp, #0x14]
	bl Div
	ldrh r1, [r4, #4]
	adds r1, r1, r0
	strh r1, [r4, #4]
_081AAFE4:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	adds r4, #0xd0
	movs r3, #1
	add sl, r3
	ldr r0, _081AB014 @ =0x00000CAA
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _081AAF76
_081AAFFE:
	ldr r0, [sp, #0x10]
	bl FUN_081aa924
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AB014: .4byte 0x00000CAA
_081AB018: .4byte 0x00000674
_081AB01C: .4byte 0x00000716
_081AB020: .4byte 0x00000714

	thumb_func_start FUN_081ab024
FUN_081ab024: @ 0x081AB024
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	movs r5, #0
	ldr r0, _081AB060 @ =0x00000CAA
	adds r6, r3, r0
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r5, r0
	bge _081AB058
	ldr r2, [r1, #4]
	ldr r1, [r1]
	ldr r7, _081AB064 @ =0x00000714
	adds r4, r3, r7
	ldr r0, _081AB068 @ =0x00000674
	adds r3, r3, r0
_081AB042:
	str r1, [r3]
	str r2, [r3, #4]
	str r1, [r4]
	str r2, [r4, #4]
	adds r4, #0xd0
	adds r3, #0xd0
	adds r5, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r5, r0
	blt _081AB042
_081AB058:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AB060: .4byte 0x00000CAA
_081AB064: .4byte 0x00000714
_081AB068: .4byte 0x00000674

	thumb_func_start FUN_081ab06c
FUN_081ab06c: @ 0x081AB06C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x28
	adds r4, r0, #0
	ldr r5, _081AB100 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r5
	movs r2, #0x18
	orrs r0, r2
	ldr r1, _081AB104 @ =0x0000FFFF
	mov r8, r1
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r5
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r6, #0
	str r6, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r5
	str r0, [r2, #4]
	ldr r3, _081AB108 @ =FUN_081a6720
	str r4, [sp]
	adds r0, r4, #0
	add r1, sp, #8
	bl FUN_080e3834
	ldr r0, [sp, #0x18]
	ands r0, r5
	movs r2, #0x20
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r5
	orrs r0, r2
	str r0, [r1, #4]
	str r6, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r5
	str r0, [r2, #4]
	ldr r3, _081AB10C @ =FUN_081a66e0
	str r6, [sp]
	str r4, [sp, #4]
	adds r0, r4, #0
	bl FUN_080e3984
	movs r0, #0x94
	lsls r0, r0, #1
	adds r4, r4, r0
	movs r0, #0x80
	lsls r0, r0, #3
	ldrh r1, [r4, #6]
	orrs r0, r1
	strh r0, [r4, #6]
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081AB100: .4byte 0xFFFF0000
_081AB104: .4byte 0x0000FFFF
_081AB108: .4byte FUN_081a6720
_081AB10C: .4byte FUN_081a66e0

	thumb_func_start FUN_081ab110
FUN_081ab110: @ 0x081AB110
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	movs r3, #0xca
	lsls r3, r3, #4
	adds r2, r5, r3
	ldrh r1, [r2]
	ldr r0, _081AB178 @ =0x0000FFFD
	ands r0, r1
	movs r3, #0
	movs r1, #0
	strh r0, [r2]
	ldr r2, _081AB17C @ =0x00000C4D
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r2, _081AB180 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081AB184 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081AB188 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	ldr r2, _081AB18C @ =0x00000CB9
	adds r1, r5, r2
	strb r0, [r1]
	ldr r1, _081AB190 @ =0x00000C45
	adds r0, r5, r1
	strb r3, [r0]
	adds r2, #0x3f
	adds r1, r5, r2
	ldr r3, _081AB194 @ =0x0000025D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AB198
	ldr r2, [r4, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _081AB1A2
	.align 2, 0
_081AB178: .4byte 0x0000FFFD
_081AB17C: .4byte 0x00000C4D
_081AB180: .4byte 0x030046B8
_081AB184: .4byte 0x000003FF
_081AB188: .4byte 0x0203B400
_081AB18C: .4byte 0x00000CB9
_081AB190: .4byte 0x00000C45
_081AB194: .4byte 0x0000025D
_081AB198:
	ldr r2, [r4, #0x44]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_081AB1A2:
	ldr r1, _081AB228 @ =0x00000CF8
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r4, #8]
	str r1, [r4, #0xc]
	adds r0, r4, #0
	bl FUN_081ac088
	adds r1, r4, #0
	adds r1, #8
	adds r0, r5, #0
	bl FUN_081ab024
	adds r0, r4, #0
	bl FUN_081a97a4
	movs r2, #0x95
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, #8
	bl ClearMemory
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	movs r2, #0
	strb r2, [r0]
	ldr r5, _081AB22C @ =0x00000469
	adds r0, r4, r5
	strb r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	adds r5, #0x1b
	adds r0, r4, r5
	str r2, [r0]
	ldr r1, _081AB230 @ =0x0000046C
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r3, [r0]
	subs r5, #0x17
	adds r0, r4, r5
	strb r1, [r0]
	subs r5, #2
	adds r0, r4, r5
	strb r2, [r0]
	adds r5, #0xe8
	adds r0, r4, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081AB228: .4byte 0x00000CF8
_081AB22C: .4byte 0x00000469
_081AB230: .4byte 0x0000046C

	thumb_func_start FUN_081ab234
FUN_081ab234: @ 0x081AB234
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r7, [r0]
	mov r0, ip
	ldr r3, [r0, #0x44]
	ldr r2, _081AB270 @ =0x085B0A08
	ldr r1, _081AB274 @ =0x00000CA2
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #1
	cmp r0, #0
	blt _081AB278
	asrs r1, r0, #0xc
	b _081AB27E
	.align 2, 0
_081AB270: .4byte 0x085B0A08
_081AB274: .4byte 0x00000CA2
_081AB278:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081AB27E:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	mov r6, ip
	ldr r1, [r6, #0x44]
	ldr r3, _081AB2A0 @ =0x00000CA2
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #4
	cmp r0, #0
	blt _081AB2A4
	asrs r2, r0, #0xc
	b _081AB2AA
	.align 2, 0
_081AB2A0: .4byte 0x00000CA2
_081AB2A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081AB2AA:
	ldrh r0, [r1, #0x20]
	adds r0, r0, r2
	strh r0, [r1, #0x20]
	ldr r6, _081AB2F4 @ =0x00000CA2
	adds r1, r7, r6
	ldrb r0, [r1]
	adds r0, #8
	strb r0, [r1]
	movs r5, #1
	mov r8, r5
	ldr r0, _081AB2F8 @ =0x00000CAA
	adds r1, r7, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	subs r0, #1
	cmp r8, r0
	bge _081AB332
	ldr r3, _081AB2FC @ =0x085B0A08
	mov sl, r3
	mov sb, r1
	adds r3, r7, #0
	adds r3, #0xd0
	ldr r4, _081AB300 @ =0x000007D9
	adds r2, r7, r4
	movs r4, #0xd0
	lsls r4, r4, #1
_081AB2DE:
	ldrb r0, [r2]
	lsls r0, r0, #1
	add r0, sl
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r0, r0, #2
	cmp r0, #0
	blt _081AB304
	asrs r0, r0, #0xc
	b _081AB30A
	.align 2, 0
_081AB2F4: .4byte 0x00000CA2
_081AB2F8: .4byte 0x00000CAA
_081AB2FC: .4byte 0x085B0A08
_081AB300: .4byte 0x000007D9
_081AB304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081AB30A:
	ldr r6, _081AB3C0 @ =0x00000674
	adds r1, r3, r6
	muls r0, r5, r0
	ldrh r6, [r1]
	adds r0, r0, r6
	strh r0, [r1]
	ldrb r0, [r2]
	adds r0, #8
	strb r0, [r2]
	rsbs r5, r5, #0
	adds r3, r3, r4
	adds r2, r2, r4
	movs r0, #2
	add r8, r0
	mov r1, sb
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, #1
	cmp r8, r0
	blt _081AB2DE
_081AB332:
	mov r1, ip
	ldr r0, [r1, #0x44]
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r2, #0
	mov r8, r2
	ldr r3, _081AB3C4 @ =0x00000CAA
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r0, #1
	cmp r8, r0
	blt _081AB352
	b _081AB48A
_081AB352:
	add r6, sp, #4
	mov sl, r6
	add r6, sp, #0xc
	add r5, sp, #0x14
	movs r0, #0x80
	lsls r0, r0, #1
	mov sb, r0
_081AB360:
	movs r0, #0xd0
	mov r2, r8
	muls r2, r0, r2
	adds r2, r2, r7
	ldr r1, _081AB3C8 @ =0x00000744
	adds r2, r2, r1
	ldrh r0, [r2]
	ldrh r1, [r6]
	subs r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r2, #0
	str r2, [sp]
	mov r0, sp
	add r1, sp, #0x1c
	ldr r2, _081AB3CC @ =0x05000002
	bl CpuSet
	mov r3, sb
	movs r4, #0xc0
	lsls r4, r4, #2
	subs r1, r3, r4
	adds r1, #1
	add r2, sp, #0x1c
	movs r3, #0
	ldrsh r0, [r2, r3]
	adds r4, r1, #0
	muls r4, r0, r4
	movs r0, #0xc0
	lsls r0, r0, #2
	mov r3, sb
	subs r1, r0, r3
	movs r3, #0
	ldrsh r0, [r5, r3]
	muls r0, r1, r0
	adds r0, r4, r0
	mov ip, r2
	cmp r0, #0
	blt _081AB3D0
	asrs r1, r0, #0xa
	b _081AB3D6
	.align 2, 0
_081AB3C0: .4byte 0x00000674
_081AB3C4: .4byte 0x00000CAA
_081AB3C8: .4byte 0x00000744
_081AB3CC: .4byte 0x05000002
_081AB3D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081AB3D6:
	ldrh r0, [r6]
	adds r0, r0, r1
	mov r4, sl
	strh r0, [r4]
	mov r0, sb
	movs r1, #0xc0
	lsls r1, r1, #2
	subs r3, r0, r1
	adds r1, r3, #1
	mov r2, ip
	movs r4, #2
	ldrsh r0, [r2, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	mov r0, sb
	rsbs r2, r0, #0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r1, r2, r1
	str r1, [sp, #0x24]
	movs r1, #2
	ldrsh r0, [r5, r1]
	ldr r1, [sp, #0x24]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r4, #0
	orrs r0, r4
	cmp r0, #0
	blt _081AB414
	asrs r1, r0, #0xa
	b _081AB41A
_081AB414:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081AB41A:
	ldrh r0, [r6, #2]
	adds r0, r0, r1
	mov r1, sl
	strh r0, [r1, #2]
	adds r1, r3, #1
	mov r3, ip
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r4, r1, #0
	muls r4, r0, r4
	movs r0, #0xc0
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r2, #4
	ldrsh r0, [r5, r2]
	muls r0, r1, r0
	adds r0, r4, r0
	movs r3, #0
	orrs r0, r3
	cmp r0, #0
	blt _081AB448
	asrs r1, r0, #0xa
	b _081AB44E
_081AB448:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081AB44E:
	ldrh r0, [r6, #4]
	adds r0, r0, r1
	mov r4, sl
	strh r0, [r4, #4]
	adds r0, r7, #0
	mov r1, r8
	mov r2, sl
	bl FUN_081aa90c
	mov r1, r8
	adds r1, #1
	movs r0, #0xd0
	muls r0, r1, r0
	adds r0, r7, r0
	ldr r1, _081AB49C @ =0x00000674
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r2, #2
	add r8, r2
	ldr r3, _081AB4A0 @ =0x00000CAA
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r0, #1
	cmp r8, r0
	bge _081AB48A
	b _081AB360
_081AB48A:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AB49C: .4byte 0x00000674
_081AB4A0: .4byte 0x00000CAA

	thumb_func_start FUN_081ab4a4
FUN_081ab4a4: @ 0x081AB4A4
	push {r4, r5, r6, r7, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r4, #0
	movs r3, #0
	ldr r5, _081AB4D8 @ =0x00000CAA
	adds r2, r1, r5
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r3, r0
	bge _081AB504
	movs r6, #1
	movs r7, #3
	rsbs r7, r7, #0
	adds r5, r2, #0
	ldr r0, _081AB4DC @ =0x00000705
	adds r2, r1, r0
_081AB4CA:
	ldrb r0, [r2]
	ands r0, r6
	cmp r0, #0
	beq _081AB4E0
	movs r0, #1
	b _081AB4E2
	.align 2, 0
_081AB4D8: .4byte 0x00000CAA
_081AB4DC: .4byte 0x00000705
_081AB4E0:
	movs r0, #0
_081AB4E2:
	cmp r0, #0
	bne _081AB4F8
	cmp r4, #1
	bne _081AB4EE
	movs r4, #0
	b _081AB4F8
_081AB4EE:
	ldrb r1, [r2]
	adds r0, r7, #0
	ands r0, r1
	strb r0, [r2]
	adds r4, #1
_081AB4F8:
	adds r2, #0xd0
	adds r3, #1
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r3, r0
	blt _081AB4CA
_081AB504:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ab50c
FUN_081ab50c: @ 0x081AB50C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r7, r6, r0
	ldr r1, _081AB54C @ =0x00000CAA
	adds r0, r6, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r4, r0, #1
	cmp r4, #0
	blt _081AB5AE
	movs r0, #1
	mov ip, r0
	movs r0, #0xd0
	muls r0, r4, r0
	adds r1, r0, #0
	adds r1, #0x1c
	adds r5, r1, r7
	adds r0, #0xad
	adds r3, r0, r7
_081AB53E:
	ldrb r0, [r3]
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	beq _081AB550
	movs r0, #1
	b _081AB552
	.align 2, 0
_081AB54C: .4byte 0x00000CAA
_081AB550:
	movs r0, #0
_081AB552:
	adds r2, r0, #0
	cmp r2, #0
	bne _081AB5A4
	ldrb r1, [r3]
	mov r0, ip
	orrs r0, r1
	strb r0, [r3]
	ldr r0, _081AB59C @ =0x00000CBA
	adds r1, r6, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r0, _081AB5A0 @ =0x00240004
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r5, #0
	movs r1, #0x10
	movs r2, #0x40
	movs r3, #0x2a
	bl FUN_080d85d8
	movs r0, #0xd0
	muls r0, r4, r0
	adds r5, r7, r0
	movs r4, #7
_081AB58A:
	adds r0, r5, #0
	adds r0, #0x1c
	bl FUN_081acc74
	subs r4, #1
	cmp r4, #0
	bge _081AB58A
	movs r0, #1
	b _081AB5B0
	.align 2, 0
_081AB59C: .4byte 0x00000CBA
_081AB5A0: .4byte 0x00240004
_081AB5A4:
	subs r5, #0xd0
	subs r3, #0xd0
	subs r4, #1
	cmp r4, #0
	bge _081AB53E
_081AB5AE:
	movs r0, #0
_081AB5B0:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ab5b8
FUN_081ab5b8: @ 0x081AB5B8
	push {r4, r5, r6, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r5, r1, r3
	ldr r0, _081AB5FC @ =0x00000CBA
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081AB620
	ldr r3, _081AB600 @ =0x00000CAA
	adds r0, r1, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r1, r0, #1
	cmp r1, #0
	blt _081AB620
	movs r6, #1
	adds r4, r2, #0
	movs r0, #0xd0
	muls r0, r1, r0
	adds r3, r0, r5
	adds r0, #0xad
	adds r2, r0, r5
_081AB5EE:
	ldrb r0, [r2]
	ands r0, r6
	cmp r0, #0
	beq _081AB604
	movs r0, #1
	b _081AB606
	.align 2, 0
_081AB5FC: .4byte 0x00000CBA
_081AB600: .4byte 0x00000CAA
_081AB604:
	movs r0, #0
_081AB606:
	cmp r0, #0
	bne _081AB618
	ldrb r0, [r2]
	adds r1, r6, #0
	orrs r1, r0
	strb r1, [r2]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
_081AB618:
	subs r3, #0xd0
	subs r2, #0xd0
	cmp r3, r5
	bge _081AB5EE
_081AB620:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ab628
FUN_081ab628: @ 0x081AB628
	push {r4, r5, r6, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r5, r1, r3
	ldr r0, _081AB66C @ =0x00000CBA
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081AB690
	ldr r3, _081AB670 @ =0x00000CAA
	adds r0, r1, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r1, r0, #1
	cmp r1, #0
	blt _081AB690
	movs r6, #1
	adds r4, r2, #0
	movs r0, #0xd0
	muls r0, r1, r0
	adds r3, r0, r5
	adds r0, #0xad
	adds r2, r0, r5
_081AB65E:
	ldrb r0, [r2]
	ands r0, r6
	cmp r0, #0
	beq _081AB674
	movs r0, #1
	b _081AB676
	.align 2, 0
_081AB66C: .4byte 0x00000CBA
_081AB670: .4byte 0x00000CAA
_081AB674:
	movs r0, #0
_081AB676:
	cmp r0, #0
	bne _081AB688
	ldrb r0, [r2]
	adds r1, r6, #0
	orrs r1, r0
	strb r1, [r2]
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
_081AB688:
	subs r3, #0xd0
	subs r2, #0xd0
	cmp r3, r5
	bge _081AB65E
_081AB690:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ab698
FUN_081ab698: @ 0x081AB698
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, sl
	ldr r0, [r0]
	mov r8, r0
	movs r1, #0x80
	lsls r1, r1, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	add r0, sl
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081AB6C4
	b _081AB7EE
_081AB6C4:
	movs r0, #0
	mov sb, r0
	ldr r0, _081AB6F0 @ =0x00000CAA
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sb, r0
	blt _081AB6D6
	b _081AB7EE
_081AB6D6:
	ldr r7, _081AB6F4 @ =0x00000676
	add r7, r8
	ldr r6, _081AB6F8 @ =0x00000674
	add r6, r8
	ldr r3, _081AB6FC @ =0x00000705
	add r3, r8
_081AB6E2:
	movs r1, #2
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081AB700
	movs r0, #1
	b _081AB702
	.align 2, 0
_081AB6F0: .4byte 0x00000CAA
_081AB6F4: .4byte 0x00000676
_081AB6F8: .4byte 0x00000674
_081AB6FC: .4byte 0x00000705
_081AB700:
	movs r0, #0
_081AB702:
	cmp r0, #0
	beq _081AB7D6
	movs r1, #1
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081AB714
	movs r0, #1
	b _081AB716
_081AB714:
	movs r0, #0
_081AB716:
	cmp r0, #0
	bne _081AB7D6
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081AB73E
	cmp r1, #0
	blt _081AB73E
	ldr r0, _081AB744 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081AB73E
	ldr r0, _081AB748 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081AB74C
_081AB73E:
	movs r4, #0
	b _081AB75A
	.align 2, 0
_081AB744: .4byte 0x030046A8
_081AB748: .4byte 0x030046AC
_081AB74C:
	ldr r0, _081AB770 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081AB75A:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp]
	bl FUN_08234224
	ldr r3, [sp]
	cmp r0, #0
	beq _081AB774
	adds r0, #4
	b _081AB780
	.align 2, 0
_081AB770: .4byte 0x030046A4
_081AB774:
	ldr r0, _081AB794 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AB780:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081AB798
	cmp r2, #2
	beq _081AB79C
	b _081AB7A0
	.align 2, 0
_081AB794: .4byte 0x030046A4
_081AB798:
	ldrb r0, [r5, #4]
	b _081AB79E
_081AB79C:
	ldrb r0, [r5]
_081AB79E:
	subs r1, r1, r0
_081AB7A0:
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, r1
	beq _081AB7D6
	cmp r0, r1
	bge _081AB7C4
	subs r0, r1, r0
	cmp r0, #0
	bge _081AB7B4
	rsbs r0, r0, #0
_081AB7B4:
	cmp r0, #0xff
	ble _081AB7C0
	mov r1, sl
	ldrh r0, [r1, #0xa]
	strh r0, [r7]
	b _081AB7D6
_081AB7C0:
	strh r1, [r7]
	b _081AB7D6
_081AB7C4:
	subs r0, r1, r0
	movs r1, #0xa
	str r3, [sp]
	bl Div
	ldrh r1, [r7]
	adds r1, r1, r0
	strh r1, [r7]
	ldr r3, [sp]
_081AB7D6:
	adds r7, #0xd0
	adds r6, #0xd0
	adds r3, #0xd0
	movs r2, #1
	add sb, r2
	ldr r0, _081AB800 @ =0x00000CAA
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sb, r0
	bge _081AB7EE
	b _081AB6E2
_081AB7EE:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AB800: .4byte 0x00000CAA

	thumb_func_start FUN_081ab804
FUN_081ab804: @ 0x081AB804
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	movs r2, #0
	mov sb, r2
	ldr r7, _081AB844 @ =0x00000CAA
	adds r0, r6, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sb, r0
	bge _081AB8FA
	movs r2, #0xd0
	mov r8, r2
	adds r4, r6, #0
	ldr r7, _081AB848 @ =0x0000071E
	adds r3, r6, r7
	movs r0, #2
	mov ip, r0
	ldr r1, _081AB84C @ =0x00000705
	adds r5, r6, r1
_081AB836:
	ldrb r0, [r5]
	mov r2, ip
	ands r0, r2
	cmp r0, #0
	beq _081AB850
	movs r0, #1
	b _081AB852
	.align 2, 0
_081AB844: .4byte 0x00000CAA
_081AB848: .4byte 0x0000071E
_081AB84C: .4byte 0x00000705
_081AB850:
	movs r0, #0
_081AB852:
	cmp r0, #0
	beq _081AB8E4
	movs r1, #1
	ldrb r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081AB864
	movs r0, #1
	b _081AB866
_081AB864:
	movs r0, #0
_081AB866:
	cmp r0, #0
	bne _081AB8E4
	ldr r7, _081AB8A0 @ =0x00000674
	adds r1, r4, r7
	ldr r0, _081AB8A4 @ =0x0000071C
	adds r2, r4, r0
	ldrh r0, [r2]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldr r0, _081AB8A8 @ =0x00000676
	adds r1, r4, r0
	ldrh r0, [r3]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r3, #2]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _081AB8AC
	asrs r1, r0, #1
	b _081AB8B2
	.align 2, 0
_081AB8A0: .4byte 0x00000674
_081AB8A4: .4byte 0x0000071C
_081AB8A8: .4byte 0x00000676
_081AB8AC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081AB8B2:
	ldr r2, _081AB8C4 @ =0x0000071C
	adds r0, r4, r2
	strh r1, [r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r0, #0
	blt _081AB8C8
	asrs r0, r0, #1
	b _081AB8CE
	.align 2, 0
_081AB8C4: .4byte 0x0000071C
_081AB8C8:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081AB8CE:
	strh r0, [r3]
	movs r1, #2
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _081AB8DC
	asrs r0, r0, #1
	b _081AB8E2
_081AB8DC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081AB8E2:
	strh r0, [r3, #2]
_081AB8E4:
	adds r4, #0xd0
	adds r3, #0xd0
	add r5, r8
	movs r2, #1
	add sb, r2
	ldr r7, _081AB908 @ =0x00000CAA
	adds r0, r6, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sb, r0
	blt _081AB836
_081AB8FA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AB908: .4byte 0x00000CAA

	thumb_func_start FUN_081ab90c
FUN_081ab90c: @ 0x081AB90C
	push {lr}
	cmp r1, #0
	beq _081AB924
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _081AB928 @ =0x00000CA2
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_081AB924:
	pop {r0}
	bx r0
	.align 2, 0
_081AB928: .4byte 0x00000CA2

	thumb_func_start FUN_081ab92c
FUN_081ab92c: @ 0x081AB92C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r1, r0, #0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r0, [r0]
	mov ip, r0
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	movs r3, #2
	ldrsh r0, [r1, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r2, r2, r0
	movs r3, #4
	ldrsh r0, [r1, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	adds r6, r2, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r6, r0
	ble _081AB974
	movs r6, #0xff
	b _081AB97E
_081AB974:
	cmp r6, #0x80
	ble _081AB97C
	movs r6, #0x7f
	b _081AB97E
_081AB97C:
	movs r6, #0x3f
_081AB97E:
	movs r7, #0
	ldr r0, _081AB9AC @ =0x00000CAA
	add r0, ip
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r7, r0
	bge _081ABA5A
	movs r3, #0xd0
	mov sl, r3
	ldr r0, _081AB9B0 @ =0x085B0A08
	mov sb, r0
	ldr r1, _081AB9B4 @ =0x030046B8
	mov r8, r1
	ldr r4, _081AB9B8 @ =0x00000705
	add r4, ip
_081AB99C:
	ldrb r0, [r4]
	movs r2, #2
	ands r0, r2
	cmp r0, #0
	beq _081AB9BC
	movs r0, #1
	b _081AB9BE
	.align 2, 0
_081AB9AC: .4byte 0x00000CAA
_081AB9B0: .4byte 0x085B0A08
_081AB9B4: .4byte 0x030046B8
_081AB9B8: .4byte 0x00000705
_081AB9BC:
	movs r0, #0
_081AB9BE:
	cmp r0, #0
	beq _081ABA4A
	ldrb r0, [r4]
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _081AB9D0
	movs r0, #1
	b _081AB9D2
_081AB9D0:
	movs r0, #0
_081AB9D2:
	cmp r0, #0
	bne _081ABA4A
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _081ABA14 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081ABA18 @ =0x0203B400
	adds r0, r0, r3
	ldrh r2, [r0]
	mov r3, sl
	muls r3, r7, r3
	add r3, ip
	ldr r0, _081ABA1C @ =0x0000071C
	adds r3, r3, r0
	ands r2, r6
	movs r5, #0xc
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081ABA20
	asrs r1, r0, #0xc
	b _081ABA26
	.align 2, 0
_081ABA14: .4byte 0x000003FF
_081ABA18: .4byte 0x0203B400
_081ABA1C: .4byte 0x0000071C
_081ABA20:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081ABA26:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081ABA42
	asrs r0, r0, #0xc
	b _081ABA48
_081ABA42:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081ABA48:
	strh r0, [r3, #4]
_081ABA4A:
	add r4, sl
	adds r7, #1
	ldr r0, _081ABA68 @ =0x00000CAA
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r7, r0
	blt _081AB99C
_081ABA5A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081ABA68: .4byte 0x00000CAA

	thumb_func_start FUN_081aba6c
FUN_081aba6c: @ 0x081ABA6C
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r3, r1
	ldr r4, [r0]
	movs r1, #2
	movs r2, #0xca
	lsls r2, r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081ABA8C
	movs r0, #1
	b _081ABA8E
_081ABA8C:
	movs r0, #0
_081ABA8E:
	cmp r0, #0
	beq _081ABAD8
	movs r2, #4
	movs r5, #0x8d
	lsls r5, r5, #3
	adds r0, r3, r5
	movs r1, #0
	strb r1, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r1, [r0]
	adds r5, #1
	adds r0, r3, r5
	strb r2, [r0]
	ldr r2, _081ABAF0 @ =0x00000484
	adds r0, r3, r2
	str r1, [r0]
	adds r5, #2
	adds r1, r3, r5
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r3, r0
	ldr r1, _081ABAF4 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _081ABAF8 @ =0x00000544
	adds r1, r3, r2
	movs r0, #0xb4
	strh r0, [r1]
	movs r5, #0xde
	lsls r5, r5, #1
	adds r1, r3, r5
	movs r0, #2
	strh r0, [r1]
_081ABAD8:
	movs r1, #0xca
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r1, #3
	rsbs r1, r1, #0
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081ABAF0: .4byte 0x00000484
_081ABAF4: .4byte 0xFFEFFFFF
_081ABAF8: .4byte 0x00000544

	thumb_func_start FUN_081abafc
FUN_081abafc: @ 0x081ABAFC
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081ABB6A
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x20
	movs r2, #0xca
	lsls r2, r2, #4
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081ABB2C
	movs r0, #1
	b _081ABB2E
_081ABB2C:
	movs r0, #0
_081ABB2E:
	adds r2, r0, #0
	cmp r2, #0
	bne _081ABB6A
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	ldr r0, _081ABB74 @ =0x00000C42
	adds r1, r1, r0
	ldrh r0, [r5, #0x3e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	add r4, sp, #0xc
	str r2, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _081ABB78 @ =0x05000002
	bl CpuSet
	ldrh r1, [r5, #0x3e]
	adds r3, r6, #0
	adds r3, #0x1c
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0805fe7c
_081ABB6A:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081ABB74: .4byte 0x00000C42
_081ABB78: .4byte 0x05000002

	thumb_func_start FUN_081abb7c
FUN_081abb7c: @ 0x081ABB7C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081abb80
FUN_081abb80: @ 0x081ABB80
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _081ABC58 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _081ABC5C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x10
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r7, #0
	ldr r0, _081ABC60 @ =0x00000CAA
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov sb, r1
	cmp r7, r0
	bge _081ABC48
_081ABBD2:
	movs r0, #0xd0
	adds r4, r7, #0
	muls r4, r0, r4
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r4, r4, r3
	add r4, r8
	adds r5, r4, #0
	adds r5, #0x48
	ldrh r1, [r6]
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	mov r2, sb
	str r2, [sp, #8]
	adds r0, r5, #0
	ldr r2, _081ABC64 @ =0x00002401
	movs r3, #0
	bl FUN_0823646c
	movs r3, #0x89
	lsls r3, r3, #2
	adds r0, r6, r3
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r2, [r0]
	adds r3, #0x18
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r6, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_082364f8
	adds r1, r4, #0
	adds r1, #0x1c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	ldr r1, _081ABC68 @ =FUN_081abb7c
	adds r2, r4, #0
	bl FUN_0823651c
	adds r7, #1
	ldr r0, _081ABC60 @ =0x00000CAA
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	blt _081ABBD2
_081ABC48:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081ABC58: .4byte 0xFFFF0000
_081ABC5C: .4byte 0x0000FFFF
_081ABC60: .4byte 0x00000CAA
_081ABC64: .4byte 0x00002401
_081ABC68: .4byte FUN_081abb7c

	thumb_func_start FUN_081abc6c
FUN_081abc6c: @ 0x081ABC6C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xe
	movs r2, #0xd
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0xe
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #0xf
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0xe
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081abca4
FUN_081abca4: @ 0x081ABCA4
	movs r0, #0x18
	bx lr

	thumb_func_start FUN_081abca8
FUN_081abca8: @ 0x081ABCA8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081ABD06
	cmp r1, #0
	blt _081ABD06
	ldr r0, _081ABD0C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081ABD06
	ldr r0, _081ABD10 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081ABD14
_081ABD06:
	movs r4, #0
	b _081ABD22
	.align 2, 0
_081ABD0C: .4byte 0x030046A8
_081ABD10: .4byte 0x030046AC
_081ABD14:
	ldr r0, _081ABD34 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081ABD22:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081ABD38
	adds r0, #4
	b _081ABD44
	.align 2, 0
_081ABD34: .4byte 0x030046A4
_081ABD38:
	ldr r0, _081ABD58 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ABD44:
	ldrh r6, [r0, #2]
	mov r7, sp
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081ABD5C
	adds r0, #4
	b _081ABD68
	.align 2, 0
_081ABD58: .4byte 0x030046A4
_081ABD5C:
	ldr r0, _081ABD7C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ABD68:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ABD80
	cmp r2, #2
	beq _081ABD84
	b _081ABD88
	.align 2, 0
_081ABD7C: .4byte 0x030046A4
_081ABD80:
	ldrb r0, [r7, #4]
	b _081ABD86
_081ABD84:
	ldrb r0, [r7]
_081ABD86:
	subs r1, r1, r0
_081ABD88:
	ldr r2, _081ABDD0 @ =0x00000472
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, r1
	blt _081ABD9A
	movs r0, #0x43
	ands r6, r0
	cmp r6, #0
	beq _081ABDAC
_081ABD9A:
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
_081ABDAC:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xa4
	movs r0, #0xca
	lsls r0, r0, #4
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081ABDD4
	movs r0, #1
	b _081ABDD6
	.align 2, 0
_081ABDD0: .4byte 0x00000472
_081ABDD4:
	movs r0, #0
_081ABDD6:
	cmp r0, #0
	beq _081ABDE8
	ldr r1, _081ABDE4 @ =0x00000C4D
	add r1, r8
	movs r0, #0
	strb r0, [r1]
	b _081ABECA
	.align 2, 0
_081ABDE4: .4byte 0x00000C4D
_081ABDE8:
	ldr r0, [r5, #0x18]
	ldrb r0, [r0]
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _081ABEC4
	ldr r1, _081ABE6C @ =0x00000C4D
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bls _081ABECA
	ldr r2, _081ABE70 @ =0x00000CB9
	add r2, r8
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r2]
	adds r0, r5, #0
	bl FUN_081a97a4
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _081ABE74 @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r1]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081ABE7C
	ldr r3, _081ABE78 @ =0xFFFFFF00
	adds r1, r1, r3
	b _081ABE8A
	.align 2, 0
_081ABE6C: .4byte 0x00000C4D
_081ABE70: .4byte 0x00000CB9
_081ABE74: .4byte 0x000004A4
_081ABE78: .4byte 0xFFFFFF00
_081ABE7C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081ABE8A
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081ABE8A:
	cmp r1, #0
	bge _081ABE90
	rsbs r1, r1, #0
_081ABE90:
	cmp r1, #0x20
	ble _081ABECA
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081ABEBC @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #0x1a
	adds r0, r5, r3
	str r1, [r0]
	ldr r1, _081ABEC0 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _081ABECA
	.align 2, 0
_081ABEBC: .4byte 0x00000469
_081ABEC0: .4byte 0x0000046C
_081ABEC4:
	ldr r0, _081ABED8 @ =0x00000C4D
	add r0, r8
	strb r1, [r0]
_081ABECA:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081ABED8: .4byte 0x00000C4D

	thumb_func_start FUN_081abedc
FUN_081abedc: @ 0x081ABEDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	ldr r2, _081AC034 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x50
	orrs r0, r1
	ldr r1, _081AC038 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r1, #0x3c
	orrs r0, r1
	str r0, [sp, #0x14]
	ldr r4, _081AC03C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _081AC040 @ =0x000003FF
	mov sl, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _081AC044 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	movs r0, #4
	mov sb, r0
	str r0, [sp]
	movs r0, #0x14
	mov r8, r0
	str r0, [sp, #4]
	movs r6, #2
	str r6, [sp, #8]
	movs r5, #1
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x20
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _081AC044 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r5
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x40
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _081AC044 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x5e
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _081AC044 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r5
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0x80
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _081AC044 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r1, r0
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0xc4
	bl FUN_080ddcc8
	ldr r0, [r4]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _081AC044 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r5
	adds r1, #1
	mov r0, sb
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r5, [sp, #0xc]
	adds r0, r7, #0
	add r2, sp, #0x10
	movs r3, #0xf0
	bl FUN_080ddcc8
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AC034: .4byte 0xFFFF0000
_081AC038: .4byte 0x0000FFFF
_081AC03C: .4byte 0x030046B8
_081AC040: .4byte 0x000003FF
_081AC044: .4byte 0x0203B400

	thumb_func_start FUN_081ac048
FUN_081ac048: @ 0x081AC048
	push {lr}
	adds r1, r0, #0
	ldr r2, _081AC064 @ =0x00000544
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081AC078
	cmp r0, #0x3b
	bhi _081AC06C
	ldr r0, _081AC068 @ =0x00000482
	adds r1, r1, r0
	movs r0, #2
	b _081AC07E
	.align 2, 0
_081AC064: .4byte 0x00000544
_081AC068: .4byte 0x00000482
_081AC06C:
	ldr r2, _081AC074 @ =0x00000482
	adds r1, r1, r2
	movs r0, #3
	b _081AC07E
	.align 2, 0
_081AC074: .4byte 0x00000482
_081AC078:
	ldr r0, _081AC084 @ =0x00000482
	adds r1, r1, r0
	movs r0, #1
_081AC07E:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081AC084: .4byte 0x00000482

	thumb_func_start FUN_081ac088
FUN_081ac088: @ 0x081AC088
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r4, [r1]
	adds r2, #0x8a
	adds r1, r0, r2
	movs r0, #0xc5
	lsls r0, r0, #4
	adds r2, r4, r0
	movs r3, #5
_081AC09E:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _081AC09E
	ldr r2, _081AC0B8 @ =0x00000C4C
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081AC0B8: .4byte 0x00000C4C

	thumb_func_start FUN_081ac0bc
FUN_081ac0bc: @ 0x081AC0BC
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r3, #0
	movs r4, #0xc5
	lsls r4, r4, #4
	adds r2, r0, r4
_081AC0CE:
	ldrh r0, [r2]
	cmp r0, r1
	bne _081AC0D8
	movs r0, #1
	b _081AC0E2
_081AC0D8:
	adds r2, #2
	adds r3, #1
	cmp r3, #5
	ble _081AC0CE
	movs r0, #0
_081AC0E2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ac0e8
FUN_081ac0e8: @ 0x081AC0E8
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r4, _081AC114 @ =0x00000C4C
	adds r3, r2, r4
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r4, #4
	adds r2, r2, r4
	adds r2, r2, r0
	strh r1, [r2]
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081AC114: .4byte 0x00000C4C

	thumb_func_start FUN_081ac118
FUN_081ac118: @ 0x081AC118
	push {r4, r5, r6, lr}
	movs r2, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r1, r0, r3
	movs r3, #0
	strb r3, [r1]
	ldr r4, _081AC16C @ =0x00000469
	adds r1, r0, r4
	strb r2, [r1]
	ldr r6, _081AC170 @ =0x0000046A
	adds r1, r0, r6
	strb r3, [r1]
	ldr r2, _081AC174 @ =0x00000484
	adds r1, r0, r2
	str r3, [r1]
	adds r4, #3
	adds r1, r0, r4
	movs r2, #1
	strb r2, [r1]
	ldr r5, _081AC178 @ =FUN_080e48d0
	movs r4, #0x10
	adds r6, #3
	adds r1, r0, r6
	strb r2, [r1]
	ldr r2, _081AC17C @ =0x0000046B
	adds r1, r0, r2
	strb r3, [r1]
	adds r6, #0xe6
	adds r1, r0, r6
	strb r4, [r1]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r1, r0, r2
	str r5, [r1]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r0, r4
	strh r3, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081AC16C: .4byte 0x00000469
_081AC170: .4byte 0x0000046A
_081AC174: .4byte 0x00000484
_081AC178: .4byte FUN_080e48d0
_081AC17C: .4byte 0x0000046B

	thumb_func_start FUN_081ac180
FUN_081ac180: @ 0x081AC180
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ac184
FUN_081ac184: @ 0x081AC184
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081AC260
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	ldr r2, _081AC1B8 @ =0x00000553
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0x26
	bne _081AC1BC
	movs r3, #0xf4
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	lsls r1, r0, #1
	b _081AC1C4
	.align 2, 0
_081AC1B8: .4byte 0x00000553
_081AC1BC:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
_081AC1C4:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, r1
	bhi _081AC260
	mov r5, sp
	adds r3, r4, #0
	adds r3, #8
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, r0, #0
	adds r2, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #4
	ldrsh r1, [r5, r3]
	bl FUN_0823785c
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #6
	ldrb r1, [r4, #5]
	adds r1, #0x10
	ands r1, r3
	asrs r1, r1, #6
	cmp r0, r1
	bne _081AC260
	movs r0, #2
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _081AC228
	rsbs r1, r1, #0
_081AC228:
	ldr r0, _081AC254 @ =0x000001FF
	cmp r1, r0
	bgt _081AC260
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	adds r1, #0x30
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x80
	ands r0, r3
	asrs r0, r0, #6
	ldr r3, _081AC258 @ =0x00000CB9
	adds r1, r2, r3
	strb r0, [r1]
	ldr r0, _081AC25C @ =0x00000CB8
	adds r2, r2, r0
	movs r0, #0xe
	strb r0, [r2]
	movs r0, #1
	b _081AC262
	.align 2, 0
_081AC254: .4byte 0x000001FF
_081AC258: .4byte 0x00000CB9
_081AC25C: .4byte 0x00000CB8
_081AC260:
	movs r0, #0
_081AC262:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ac26c
FUN_081ac26c: @ 0x081AC26C
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081AC342
	movs r2, #0x20
	movs r3, #0xca
	lsls r3, r3, #4
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081AC29C
	movs r0, #1
	b _081AC29E
_081AC29C:
	movs r0, #0
_081AC29E:
	cmp r0, #0
	bne _081AC342
	ldr r1, _081AC2C0 @ =0x0000A027
	movs r5, #0xc0
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081AC342
	movs r1, #4
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081AC2C4
	movs r0, #1
	b _081AC2C6
	.align 2, 0
_081AC2C0: .4byte 0x0000A027
_081AC2C4:
	movs r0, #0
_081AC2C6:
	cmp r0, #0
	beq _081AC30C
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, _081AC300 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
	ldr r2, _081AC304 @ =0x00000226
	adds r1, r4, r2
	ldrh r1, [r1]
	ldr r3, _081AC308 @ =0x0000022E
	adds r2, r4, r3
	ldrh r2, [r2]
	movs r5, #0x90
	lsls r5, r5, #2
	adds r3, r4, r5
	ldr r3, [r3]
	str r3, [sp]
	subs r5, #0xa
	adds r3, r4, r5
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
	b _081AC342
	.align 2, 0
_081AC300: .4byte 0xFFFFFEFF
_081AC304: .4byte 0x00000226
_081AC308: .4byte 0x0000022E
_081AC30C:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r4, r1
	subs r1, #0x28
	ldrh r2, [r0, #6]
	orrs r1, r2
	strh r1, [r0, #6]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrh r2, [r2]
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r3, r4, r5
	ldr r3, [r3]
	str r3, [sp]
	subs r5, #8
	adds r3, r4, r5
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_082364f8
_081AC342:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ac34c
FUN_081ac34c: @ 0x081AC34C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081AC38A
	movs r2, #0x30
	movs r3, #0xca
	lsls r3, r3, #4
	adds r1, r7, r3
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _081AC384
	movs r0, #1
	b _081AC386
_081AC384:
	movs r0, #0
_081AC386:
	cmp r0, #0
	beq _081AC3D4
_081AC38A:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r5, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
	movs r6, #0
	ldr r1, _081AC3CC @ =0x00000CAA
	adds r2, r7, r1
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r6, r0
	blt _081AC3B2
	b _081AC4F6
_081AC3B2:
	movs r3, #4
	ldr r5, _081AC3D0 @ =0x000006A6
	adds r1, r7, r5
_081AC3B8:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r1, #0xd0
	adds r6, #1
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r6, r0
	blt _081AC3B8
	b _081AC4F6
	.align 2, 0
_081AC3CC: .4byte 0x00000CAA
_081AC3D0: .4byte 0x000006A6
_081AC3D4:
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081AC3F0
	movs r0, #0x94
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	b _081AC400
_081AC3F0:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_081AC400:
	movs r6, #0
	ldr r2, _081AC430 @ =0x00000CAA
	adds r0, r7, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r6, r0
	bge _081AC4F6
	movs r0, #0xd4
	lsls r0, r0, #3
	adds r4, r7, r0
	ldr r1, _081AC434 @ =0x00000674
	adds r1, r1, r7
	mov sb, r1
	ldr r2, _081AC438 @ =0x00000705
	adds r2, r2, r7
	mov r8, r2
_081AC420:
	movs r1, #1
	mov r3, r8
	ldrb r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081AC43C
	movs r0, #1
	b _081AC43E
	.align 2, 0
_081AC430: .4byte 0x00000CAA
_081AC434: .4byte 0x00000674
_081AC438: .4byte 0x00000705
_081AC43C:
	movs r0, #0
_081AC43E:
	cmp r0, #0
	bne _081AC4E0
	ldrh r0, [r4, #6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r0
	strh r1, [r4, #6]
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	mov r1, sl
	ldrh r0, [r1]
	movs r2, #4
	ands r0, r2
	cmp r0, #0
	beq _081AC46C
	movs r0, #1
	b _081AC46E
_081AC46C:
	movs r0, #0
_081AC46E:
	cmp r0, #0
	beq _081AC4AC
	ldrh r1, [r4, #6]
	ldr r0, _081AC4A0 @ =0xFFFFFEFF
	ands r0, r1
	strh r0, [r4, #6]
	ldr r3, _081AC4A4 @ =0x00000226
	adds r0, r5, r3
	ldrh r1, [r0]
	ldr r2, _081AC4A8 @ =0x0000022E
	adds r0, r5, r2
	ldrh r2, [r0]
	adds r3, #0x1a
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #0xa
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
	b _081AC4E0
	.align 2, 0
_081AC4A0: .4byte 0xFFFFFEFF
_081AC4A4: .4byte 0x00000226
_081AC4A8: .4byte 0x0000022E
_081AC4AC:
	ldrh r1, [r4, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	orrs r0, r1
	strh r0, [r4, #6]
	movs r1, #0x89
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r2, [r0]
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp]
	subs r3, #8
	adds r0, r5, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_082364f8
_081AC4E0:
	adds r4, #0xd0
	movs r0, #0xd0
	add sb, r0
	add r8, r0
	adds r6, #1
	ldr r1, _081AC508 @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _081AC420
_081AC4F6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AC508: .4byte 0x00000CAA

	thumb_func_start FUN_081ac50c
FUN_081ac50c: @ 0x081AC50C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x40
	adds r2, r4, #0
	adds r2, #0xad
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	adds r1, r4, #0
	adds r1, #0xb3
	movs r0, #6
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ac538
FUN_081ac538: @ 0x081AC538
	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r0, _081AC568 @ =0x00000B58
	adds r4, r2, r0
	movs r0, #0xd0
	adds r3, r1, #0
	muls r3, r0, r3
	adds r0, r2, r3
	ldr r1, _081AC56C @ =0x0000068A
	adds r0, r0, r1
	ldr r1, _081AC570 @ =0x000001A5
	strh r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	adds r2, r2, r0
	adds r2, r2, r3
	str r4, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081AC568: .4byte 0x00000B58
_081AC56C: .4byte 0x0000068A
_081AC570: .4byte 0x000001A5

	thumb_func_start FUN_081ac574
FUN_081ac574: @ 0x081AC574
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_081AC57A:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081ac538
	adds r4, #1
	cmp r4, #5
	ble _081AC57A
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ac590
FUN_081ac590: @ 0x081AC590
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r3, [sp]
	ldr r3, _081AC690 @ =0x00000B58
	adds r7, r0, r3
	ldr r0, _081AC694 @ =0x03003584
	lsls r3, r1, #5
	ldr r0, [r0]
	lsls r2, r2, #5
	adds r2, r0, r2
	str r2, [sp, #4]
	strh r1, [r7, #0x22]
	movs r1, #0
	str r1, [sp, #8]
	adds r0, r0, r3
	mov sl, r0
_081AC5B8:
	ldr r3, [sp, #8]
	lsls r2, r3, #1
	ldr r1, [sp, #4]
	adds r0, r2, r1
	ldrh r4, [r0]
	movs r3, #0x84
	adds r3, r3, r7
	mov r8, r3
	add r8, r2
	mov r0, sl
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	mov sb, r4
	mov r1, sb
	movs r3, #0x1f
	ands r1, r3
	mov sb, r1
	subs r0, r0, r1
	lsls r0, r0, #5
	mov r1, r8
	strh r0, [r1]
	adds r6, r7, #0
	adds r6, #0xa4
	adds r6, r6, r2
	mov r3, sl
	ldrh r0, [r3]
	lsrs r0, r0, #5
	movs r1, #0x1f
	ands r0, r1
	asrs r3, r4, #5
	ands r3, r1
	subs r0, r0, r3
	lsls r0, r0, #5
	strh r0, [r6]
	adds r5, r7, #0
	adds r5, #0xc4
	adds r5, r5, r2
	mov r1, sl
	ldrh r0, [r1]
	lsrs r0, r0, #0xa
	movs r1, #0x1f
	ands r0, r1
	asrs r4, r4, #0xa
	ands r4, r1
	subs r0, r0, r4
	lsls r0, r0, #5
	strh r0, [r5]
	mov r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov ip, r0
	ldr r1, [sp]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	bl Div
	mov r1, r8
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r6, r1]
	ldr r1, [sp]
	bl Div
	strh r0, [r6]
	movs r1, #0
	ldrsh r0, [r5, r1]
	ldr r1, [sp]
	bl Div
	strh r0, [r5]
	adds r0, r7, #0
	adds r0, #0x24
	ldr r2, [sp, #0xc]
	adds r0, r0, r2
	mov r1, sb
	lsls r1, r1, #5
	strh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	adds r0, r0, r2
	ldr r3, [sp, #0x10]
	lsls r3, r3, #5
	strh r3, [r0]
	adds r0, r7, #0
	adds r0, #0x64
	adds r0, r0, r2
	lsls r4, r4, #5
	strh r4, [r0]
	movs r3, #2
	add sl, r3
	ldr r0, [sp, #8]
	adds r0, #1
	str r0, [sp, #8]
	cmp r0, #0xf
	ble _081AC5B8
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r7, #0x20]
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AC690: .4byte 0x00000B58
_081AC694: .4byte 0x03003584

	thumb_func_start FUN_081ac698
FUN_081ac698: @ 0x081AC698
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081AC78E
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _081AC71C @ =0x00000B58
	adds r2, r2, r1
	mov ip, r2
	ldrh r0, [r2, #0x20]
	cmp r0, #0
	beq _081AC792
	ldr r0, _081AC720 @ =0x00000B7C
	adds r0, r1, r0
	str r0, [sp]
	ldr r2, _081AC724 @ =0x00000BDC
	adds r2, r2, r1
	mov sl, r2
	ldr r0, _081AC728 @ =0x00000BFC
	adds r0, r0, r1
	mov sb, r0
	ldr r2, _081AC72C @ =0x00000C1C
	adds r2, r2, r1
	mov r8, r2
	mov r5, ip
	ldr r0, _081AC730 @ =0x00000BBC
	adds r4, r1, r0
	movs r7, #0
	ldr r2, _081AC734 @ =0x00000B9C
	adds r3, r1, r2
_081AC6E8:
	ldr r0, [sp]
	adds r1, r0, r7
	mov r2, sl
	adds r0, r2, r7
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	mov r2, sb
	adds r0, r2, r7
	ldrh r0, [r0]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	mov r2, r8
	adds r0, r2, r7
	ldrh r0, [r0]
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _081AC738
	asrs r0, r0, #5
	b _081AC73E
	.align 2, 0
_081AC71C: .4byte 0x00000B58
_081AC720: .4byte 0x00000B7C
_081AC724: .4byte 0x00000BDC
_081AC728: .4byte 0x00000BFC
_081AC72C: .4byte 0x00000C1C
_081AC730: .4byte 0x00000BBC
_081AC734: .4byte 0x00000B9C
_081AC738:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081AC73E:
	adds r6, r0, #0
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _081AC74C
	asrs r0, r0, #5
	b _081AC752
_081AC74C:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081AC752:
	adds r2, r0, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _081AC760
	asrs r1, r0, #5
	b _081AC766
_081AC760:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_081AC766:
	lsls r0, r2, #5
	orrs r0, r6
	lsls r1, r1, #0xa
	orrs r1, r0
	strh r1, [r5]
	adds r5, #2
	adds r4, #2
	adds r7, #2
	adds r3, #2
	mov r0, ip
	adds r0, #0x1e
	cmp r5, r0
	ble _081AC6E8
	mov r2, ip
	ldrh r0, [r2, #0x20]
	subs r0, #1
	strh r0, [r2, #0x20]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _081AC792
_081AC78E:
	movs r0, #0
	b _081AC794
_081AC792:
	movs r0, #1
_081AC794:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ac7a4
FUN_081ac7a4: @ 0x081AC7A4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	adds r0, r5, #0
	bl FUN_081ac698
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081AC7EE
	ldr r0, _081AC7D0 @ =0x00000C3C
	adds r4, r4, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081AC7D8
	movs r1, #0xd3
	lsls r1, r1, #1
	ldr r2, _081AC7D4 @ =0x000001A5
	b _081AC7DE
	.align 2, 0
_081AC7D0: .4byte 0x00000C3C
_081AC7D4: .4byte 0x000001A5
_081AC7D8:
	ldr r1, _081AC7F4 @ =0x000001A5
	movs r2, #0xd3
	lsls r2, r2, #1
_081AC7DE:
	adds r0, r5, #0
	movs r3, #0x14
	bl FUN_081ac590
	ldrb r0, [r4]
	movs r1, #1
	eors r0, r1
	strb r0, [r4]
_081AC7EE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081AC7F4: .4byte 0x000001A5

	thumb_func_start FUN_081ac7f8
FUN_081ac7f8: @ 0x081AC7F8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r6, _081AC834 @ =0x000001A5
	movs r2, #0xd3
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #0x14
	bl FUN_081ac590
	ldr r0, _081AC838 @ =0x00000C3C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x44]
	strh r6, [r0, #0x32]
	ldr r0, [r4, #0x44]
	ldr r1, _081AC83C @ =0x00000B58
	adds r5, r5, r1
	str r5, [r0, #0x38]
	adds r0, r4, #0
	bl FUN_081ac574
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081AC834: .4byte 0x000001A5
_081AC838: .4byte 0x00000C3C
_081AC83C: .4byte 0x00000B58

	thumb_func_start FUN_081ac840
FUN_081ac840: @ 0x081AC840
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r2, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r7, [r0]
	movs r3, #0xa
	ldrsh r1, [r2, r3]
	ldr r3, _081AC8B8 @ =0x00000472
	adds r0, r2, r3
	ldrh r0, [r0]
	cmp r1, r0
	bge _081AC86E
	ldr r0, [r2, #0x44]
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081AC86E:
	movs r0, #0
	mov r8, r0
	ldr r1, _081AC8BC @ =0x00000CAA
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r8, r0
	bge _081AC968
	movs r3, #0
	mov sb, r3
	ldr r0, _081AC8C0 @ =0x00000705
	adds r3, r7, r0
	ldr r1, _081AC8C4 @ =0x00000674
	adds r6, r7, r1
	movs r2, #1
	mov sl, r2
_081AC88E:
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081AC8B2
	cmp r1, #0
	blt _081AC8B2
	ldr r0, _081AC8C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081AC8B2
	ldr r0, _081AC8CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081AC8D0
_081AC8B2:
	movs r4, #0
	b _081AC8DE
	.align 2, 0
_081AC8B8: .4byte 0x00000472
_081AC8BC: .4byte 0x00000CAA
_081AC8C0: .4byte 0x00000705
_081AC8C4: .4byte 0x00000674
_081AC8C8: .4byte 0x030046A8
_081AC8CC: .4byte 0x030046AC
_081AC8D0:
	ldr r0, _081AC8F4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081AC8DE:
	adds r5, r6, #0
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp]
	bl FUN_08234224
	ldr r3, [sp]
	cmp r0, #0
	beq _081AC8F8
	adds r0, #4
	b _081AC904
	.align 2, 0
_081AC8F4: .4byte 0x030046A4
_081AC8F8:
	ldr r0, _081AC918 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AC904:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081AC91C
	cmp r2, #2
	beq _081AC920
	b _081AC924
	.align 2, 0
_081AC918: .4byte 0x030046A4
_081AC91C:
	ldrb r0, [r5, #4]
	b _081AC922
_081AC920:
	ldrb r0, [r5]
_081AC922:
	subs r1, r1, r0
_081AC924:
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, r1
	blt _081AC940
	ldrb r0, [r3]
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _081AC93A
	movs r0, #1
	b _081AC93C
_081AC93A:
	movs r0, #0
_081AC93C:
	cmp r0, #0
	beq _081AC950
_081AC940:
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r7, r2
	add r1, sb
	ldr r0, [r1]
	mov r2, sl
	orrs r0, r2
	str r0, [r1]
_081AC950:
	movs r0, #0xd0
	add sb, r0
	adds r3, #0xd0
	adds r6, #0xd0
	movs r1, #1
	add r8, r1
	ldr r2, _081AC978 @ =0x00000CAA
	adds r0, r7, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r8, r0
	blt _081AC88E
_081AC968:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081AC978: .4byte 0x00000CAA

	thumb_func_start FUN_081ac97c
FUN_081ac97c: @ 0x081AC97C
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xc4
	lsls r1, r1, #4
	adds r4, r0, r1
	ldrh r0, [r4]
	cmp r0, #0
	beq _081AC99C
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	strh r0, [r4]
_081AC99C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ac9a4
FUN_081ac9a4: @ 0x081AC9A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x40
	mov r8, r0
	ldr r4, _081AC9F4 @ =0x0203B400
	ldr r3, _081AC9F8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081AC9FC @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	add r6, sp, #0x38
	adds r4, r0, #4
	ldr r1, _081ACA00 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	mov ip, r3
	cmp r0, #0
	blt _081ACA04
	asrs r2, r0, #0xc
	b _081ACA0A
	.align 2, 0
_081AC9F4: .4byte 0x0203B400
_081AC9F8: .4byte 0x030046B8
_081AC9FC: .4byte 0x000003FF
_081ACA00: .4byte 0x085B0A08
_081ACA04:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081ACA0A:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081ACA22
	asrs r0, r0, #0xc
	b _081ACA28
_081ACA22:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081ACA28:
	movs r4, #0
	strh r0, [r6, #4]
	ldr r5, _081ACAA0 @ =0x0203B400
	mov r2, ip
	ldr r1, [r2]
	adds r1, #1
	ldr r3, _081ACAA4 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r0, r2
	subs r0, #0x10
	add r2, sp, #0x38
	strh r0, [r2, #2]
	adds r1, #1
	ands r1, r3
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x14
	ldr r2, _081ACAA8 @ =0x00001C1A
	ldr r3, _081ACAAC @ =0x0000D1B8
	movs r0, #3
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x31
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r0, #4
	str r0, [sp, #0x20]
	movs r0, #1
	str r0, [sp, #0x24]
	ldr r0, _081ACAB0 @ =0x00200004
	str r0, [sp, #0x28]
	movs r0, #0x1e
	str r0, [sp, #0x2c]
	movs r0, #8
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	mov r0, r8
	add r1, sp, #0x38
	bl FUN_081f22c0
	add sp, #0x40
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081ACAA0: .4byte 0x0203B400
_081ACAA4: .4byte 0x000003FF
_081ACAA8: .4byte 0x00001C1A
_081ACAAC: .4byte 0x0000D1B8
_081ACAB0: .4byte 0x00200004

	thumb_func_start FUN_081acab4
FUN_081acab4: @ 0x081ACAB4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x40
	mov r8, r0
	ldr r4, _081ACB00 @ =0x0203B400
	ldr r3, _081ACB04 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081ACB08 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r4, [r0]
	movs r0, #0x1f
	add r6, sp, #0x38
	ands r4, r0
	ldr r1, _081ACB0C @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	mov ip, r3
	cmp r0, #0
	blt _081ACB10
	asrs r2, r0, #0xc
	b _081ACB16
	.align 2, 0
_081ACB00: .4byte 0x0203B400
_081ACB04: .4byte 0x030046B8
_081ACB08: .4byte 0x000003FF
_081ACB0C: .4byte 0x085B0A08
_081ACB10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081ACB16:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081ACB2E
	asrs r0, r0, #0xc
	b _081ACB34
_081ACB2E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081ACB34:
	movs r4, #0
	strh r0, [r6, #4]
	ldr r5, _081ACBAC @ =0x0203B400
	mov r2, ip
	ldr r1, [r2]
	adds r1, #1
	ldr r3, _081ACBB0 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r0, r2
	subs r0, #0x10
	add r2, sp, #0x38
	strh r0, [r2, #2]
	adds r1, #1
	ands r1, r3
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x14
	ldr r2, _081ACBB4 @ =0x00001C1A
	ldr r3, _081ACBB8 @ =0x0000D1B8
	movs r0, #3
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #0x31
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r0, #4
	str r0, [sp, #0x20]
	movs r0, #1
	str r0, [sp, #0x24]
	ldr r0, _081ACBBC @ =0x00200004
	str r0, [sp, #0x28]
	movs r0, #0x1e
	str r0, [sp, #0x2c]
	movs r0, #8
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	mov r0, r8
	add r1, sp, #0x38
	bl FUN_081f22c0
	add sp, #0x40
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081ACBAC: .4byte 0x0203B400
_081ACBB0: .4byte 0x000003FF
_081ACBB4: .4byte 0x00001C1A
_081ACBB8: .4byte 0x0000D1B8
_081ACBBC: .4byte 0x00200004

	thumb_func_start FUN_081acbc0
FUN_081acbc0: @ 0x081ACBC0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	mov ip, r0
	ldr r4, _081ACC08 @ =0x0203B400
	ldr r3, _081ACC0C @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081ACC10 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r4, [r0]
	movs r0, #0x1f
	mov r6, sp
	ands r4, r0
	ldr r1, _081ACC14 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081ACC18
	asrs r2, r0, #0xc
	b _081ACC1E
	.align 2, 0
_081ACC08: .4byte 0x0203B400
_081ACC0C: .4byte 0x030046B8
_081ACC10: .4byte 0x000003FF
_081ACC14: .4byte 0x085B0A08
_081ACC18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081ACC1E:
	movs r0, #0
	strh r2, [r6]
	strh r0, [r6, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081ACC36
	asrs r0, r0, #0xc
	b _081ACC3C
_081ACC36:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081ACC3C:
	strh r0, [r6, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081ACC6C @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _081ACC70 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x14
	mov r1, sp
	strh r0, [r1, #2]
	mov r0, ip
	movs r2, #0x1e
	movs r3, #3
	bl FUN_081ee07c
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081ACC6C: .4byte 0x000003FF
_081ACC70: .4byte 0x0203B400

	thumb_func_start FUN_081acc74
FUN_081acc74: @ 0x081ACC74
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	mov ip, r0
	ldr r4, _081ACCC0 @ =0x0203B400
	ldr r3, _081ACCC4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081ACCC8 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	mov r4, sp
	adds r6, r0, #0
	subs r6, #0x10
	ldr r1, _081ACCCC @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081ACCD0
	asrs r2, r0, #0xc
	b _081ACCD6
	.align 2, 0
_081ACCC0: .4byte 0x0203B400
_081ACCC4: .4byte 0x030046B8
_081ACCC8: .4byte 0x000003FF
_081ACCCC: .4byte 0x085B0A08
_081ACCD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081ACCD6:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081ACCEE
	asrs r0, r0, #0xc
	b _081ACCF4
_081ACCEE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081ACCF4:
	strh r0, [r4, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081ACD24 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _081ACD28 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x10
	mov r1, sp
	strh r0, [r1, #2]
	mov r0, ip
	movs r2, #0x3c
	movs r3, #3
	bl FUN_081ee07c
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081ACD24: .4byte 0x000003FF
_081ACD28: .4byte 0x0203B400

	thumb_func_start FUN_081acd2c
FUN_081acd2c: @ 0x081ACD2C
	push {lr}
	sub sp, #0x10
	ldr r1, [r0, #8]
	ldr r2, [r0, #0xc]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	ldr r1, _081ACD64 @ =0x00000472
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	ldr r2, _081ACD68 @ =0x0000FFFF
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, _081ACD6C @ =0x00240004
	str r0, [sp]
	movs r0, #0x3c
	str r0, [sp, #4]
	add r0, sp, #8
	movs r1, #0
	movs r2, #0x78
	movs r3, #0x3c
	bl FUN_081f9b20
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
_081ACD64: .4byte 0x00000472
_081ACD68: .4byte 0x0000FFFF
_081ACD6C: .4byte 0x00240004

	thumb_func_start FUN_081acd70
FUN_081acd70: @ 0x081ACD70
	push {lr}
	sub sp, #8
	ldr r1, _081ACD8C @ =0x00240004
	str r1, [sp]
	movs r1, #0x3c
	str r1, [sp, #4]
	movs r1, #0x78
	movs r2, #0x78
	movs r3, #0x3c
	bl FUN_081f9b20
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_081ACD8C: .4byte 0x00240004

	thumb_func_start FUN_081acd90
FUN_081acd90: @ 0x081ACD90
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081ACDA8 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081ACDAC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081ACDAE
	.align 2, 0
_081ACDA8: .4byte 0x0000046C
_081ACDAC:
	movs r0, #0
_081ACDAE:
	cmp r0, #0
	beq _081ACDE6
	ldr r4, _081ACE88 @ =FUN_081a795c
	movs r3, #0x22
	ldr r2, _081ACE8C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _081ACE90 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _081ACE94 @ =0x00000553
	adds r0, r5, r1
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #8
	strh r0, [r1]
_081ACDE6:
	movs r4, #0xe0
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r3, r1, #0
	cmp r1, #0
	bge _081ACDF8
	rsbs r3, r1, #0
_081ACDF8:
	movs r2, #0xe2
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	adds r2, r0, #0
	cmp r0, #0
	bge _081ACE0A
	rsbs r2, r0, #0
_081ACE0A:
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #4
	movs r2, #0xc
	bl FUN_081aae88
	movs r1, #0xd7
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x28
	bl FUN_081aaa00
	ldr r6, _081ACE90 @ =0x0000046B
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _081ACEA0
	adds r0, r5, #0
	bl FUN_081a97a4
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r3, #1
	ldr r2, _081ACE8C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r3, [r0]
	adds r0, r5, r6
	strb r2, [r0]
	ldr r4, _081ACE94 @ =0x00000553
	adds r0, r5, r4
	strb r3, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r5, r6
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081ACE98 @ =0x0000046A
	adds r0, r5, r1
	strb r4, [r0]
	ldr r4, _081ACE9C @ =0x00000484
	adds r0, r5, r4
	str r2, [r0]
	adds r6, #3
	adds r0, r5, r6
	strb r3, [r0]
	b _081ACEAA
	.align 2, 0
_081ACE88: .4byte FUN_081a795c
_081ACE8C: .4byte 0x0000046D
_081ACE90: .4byte 0x0000046B
_081ACE94: .4byte 0x00000553
_081ACE98: .4byte 0x0000046A
_081ACE9C: .4byte 0x00000484
_081ACEA0:
	ldr r0, _081ACEB0 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081ACEAA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081ACEB0: .4byte 0x00000484

	thumb_func_start FUN_081aceb4
FUN_081aceb4: @ 0x081ACEB4
	ldr r1, _081ACEC0 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _081ACEC4 @ =0x085ADED4
	str r1, [r0]
	bx lr
	.align 2, 0
_081ACEC0: .4byte 0x0000063C
_081ACEC4: .4byte 0x085ADED4

	thumb_func_start FUN_081acec8
FUN_081acec8: @ 0x081ACEC8
	push {lr}
	bl FUN_081ac7a4
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_081aced4
FUN_081aced4: @ 0x081ACED4
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081ac34c
	adds r0, r4, #0
	bl FUN_081ac26c
	adds r0, r4, #0
	bl FUN_081aaa78
	adds r0, r4, #0
	bl FUN_081ab804
	adds r0, r4, #0
	bl FUN_081ab698
	adds r0, r4, #0
	bl FUN_081ac840
	movs r0, #0xc1
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r0, _081ACF10 @ =0xFFFFBFFF
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081ACF10: .4byte 0xFFFFBFFF

	thumb_func_start FUN_081acf14
FUN_081acf14: @ 0x081ACF14
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, _081ACF28 @ =0xFFFFFEDF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
	bx lr
	.align 2, 0
_081ACF28: .4byte 0xFFFFFEDF

	thumb_func_start FUN_081acf2c
FUN_081acf2c: @ 0x081ACF2C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081acec8
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _081ACF64 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
	adds r0, r4, #0
	bl FUN_081aced4
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081ACF64: .4byte 0x0000062C

	thumb_func_start FUN_081acf68
FUN_081acf68: @ 0x081ACF68
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, _081ACFC4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081ACFC8 @ =0x030047A4
	ldr r1, _081ACFCC @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081AD060
	movs r1, #4
	ldr r0, _081ACFD0 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081AD060
	movs r0, #2
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _081AD024
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _081ACFD4 @ =0x030046A0
	ldr r0, [r0]
	adds r2, #0xd0
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081ACFD8
	movs r0, #1
	b _081ACFDA
	.align 2, 0
_081ACFC4: .4byte 0x03002BE0
_081ACFC8: .4byte 0x030047A4
_081ACFCC: .4byte 0x030047A0
_081ACFD0: .4byte 0x03002BC0
_081ACFD4: .4byte 0x030046A0
_081ACFD8:
	movs r0, #0
_081ACFDA:
	cmp r0, #0
	bne _081ACFE8
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080f07d0
	b _081AD060
_081ACFE8:
	adds r0, r4, #0
	bl FUN_080eafdc
	adds r0, r4, #0
	bl FUN_080e1f48
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r1, [r1]
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e35b4
	adds r0, r4, #0
	bl FUN_080e191c
	adds r0, r4, #0
	bl FUN_080eb168
	adds r0, r4, #0
	bl FUN_080f06ac
	movs r0, #1
	b _081AD062
_081AD024:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _081AD05A
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _081AD048 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081AD04C
	movs r0, #1
	b _081AD04E
	.align 2, 0
_081AD048: .4byte 0x030046A0
_081AD04C:
	movs r0, #0
_081AD04E:
	cmp r0, #0
	beq _081AD05A
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080f0914
_081AD05A:
	adds r0, r4, #0
	bl FUN_080f06ac
_081AD060:
	movs r0, #0
_081AD062:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ad068
FUN_081ad068: @ 0x081AD068
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_081aa8d4
	ldr r0, _081AD09C @ =0x0000044C
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _081AD088
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013c70
	movs r0, #0xff
	strb r0, [r5]
_081AD088:
	ldr r2, _081AD0A0 @ =0x0000025D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AD0A4
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _081AD0AC
	.align 2, 0
_081AD09C: .4byte 0x0000044C
_081AD0A0: .4byte 0x0000025D
_081AD0A4:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_081AD0AC:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081AD0C8 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081AD0CC
	movs r0, #1
	b _081AD0CE
	.align 2, 0
_081AD0C8: .4byte 0x00000474
_081AD0CC:
	movs r0, #0
_081AD0CE:
	cmp r0, #0
	beq _081AD0DA
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_081AD0DA:
	ldr r1, _081AD134 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081AD0F2
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_081AD0F2:
	ldr r0, _081AD138 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _081AD10A
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_081AD10A:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081AD122
	adds r0, r4, #0
	bl FUN_08002a58
_081AD122:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081AD13C
	movs r0, #1
	b _081AD13E
	.align 2, 0
_081AD134: .4byte 0x0000044C
_081AD138: .4byte 0x0000044D
_081AD13C:
	movs r0, #0
_081AD13E:
	cmp r0, #0
	beq _081AD14A
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_081AD14A:
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_080ec6fc
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EnemyFlameSnake_Init
EnemyFlameSnake_Init: @ 0x081AD168
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1e0
	adds r7, r0, #0
	str r7, [sp, #0x30]
	movs r1, #0xca
	lsls r1, r1, #4
	adds r0, r7, r1
	movs r6, #0
	strh r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _081AD1F4 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x1f
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_081abc6c
	ldr r3, _081AD1F8 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AD204
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081AD1FC @ =0x0000D636
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _081AD200 @ =0x0000C102
	bl FUN_080e3804
	ldr r4, _081AD1F4 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0x60]
	cmp r1, #0x11
	beq _081AD1E2
	cmp r1, #0x17
	bne _081AD1E6
_081AD1E2:
	movs r0, #1
	strb r0, [r5, #7]
_081AD1E6:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _081AD26C
	.align 2, 0
_081AD1F4: .4byte 0x000001DF
_081AD1F8: .4byte 0x0000025D
_081AD1FC: .4byte 0x0000D636
_081AD200: .4byte 0x0000C102
_081AD204:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x20
	mov r8, r0
	str r6, [sp, #0x1c]
	add r0, sp, #0x1c
	mov r1, r8
	ldr r2, _081AD2E8 @ =0x05000002
	bl CpuSet
	ldr r0, _081AD2EC @ =0x0000CB05
	ldr r1, _081AD2F0 @ =0x0000D636
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _081AD2F4 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _081AD2F8 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0x60]
_081AD26C:
	str r7, [sp, #0x34]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	str r4, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	str r4, [r3]
	ldr r5, _081AD2FC @ =0x0000046F
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	mov sl, r0
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, _081AD300 @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x28
	str r4, [sp, #0x1c]
	add r0, sp, #0x1c
	adds r1, r5, #0
	ldr r2, _081AD2E8 @ =0x05000002
	bl CpuSet
	ldr r3, _081AD304 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1d8]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x1b0]
	mov r3, r8
	str r3, [sp, #0x1b4]
	str r6, [sp, #0x188]
	ldr r2, [sp, #0x1d8]
	adds r6, r2, #0
	cmp r0, #0
	bne _081AD2D8
	b _081AD438
_081AD2D8:
	bl VM_GetPC
	cmp r0, #0
	beq _081AD308
	bl Script_GetValue
	adds r1, r0, #0
	b _081AD30A
	.align 2, 0
_081AD2E8: .4byte 0x05000002
_081AD2EC: .4byte 0x0000CB05
_081AD2F0: .4byte 0x0000D636
_081AD2F4: .4byte 0x000004B7
_081AD2F8: .4byte 0x000001DF
_081AD2FC: .4byte 0x0000046F
_081AD300: .4byte 0x00000474
_081AD304: .4byte 0x000004B6
_081AD308:
	movs r1, #0
_081AD30A:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _081AD330 @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0xf4]
	str r4, [sp, #0xf8]
	cmp r0, #0
	beq _081AD334
	bl Script_GetValue
	adds r1, r0, #0
	b _081AD336
	.align 2, 0
_081AD330: .4byte 0x00000251
_081AD334:
	movs r1, #0
_081AD336:
	ldr r2, _081AD36C @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _081AD370 @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0xf4]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x100]
	cmp r0, #0
	beq _081AD374
	bl Script_GetValue
	b _081AD378
	.align 2, 0
_081AD36C: .4byte 0x00000252
_081AD370: .4byte 0x000004B4
_081AD374:
	ldr r4, [sp, #0xf4]
	ldrb r0, [r4]
_081AD378:
	strb r0, [r6]
	ldr r5, [sp, #0xf4]
	ldrb r1, [r5]
	ldr r6, [sp, #0x100]
	ldrb r2, [r6]
	add r0, sp, #0x28
	bl FUN_08234f90
	add r0, sp, #0x28
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081AD3B0
	cmp r1, #0
	blt _081AD3B0
	ldr r0, _081AD3B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081AD3B0
	ldr r0, _081AD3B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081AD3BC
_081AD3B0:
	movs r1, #0
	b _081AD3CA
	.align 2, 0
_081AD3B4: .4byte 0x030046A8
_081AD3B8: .4byte 0x030046AC
_081AD3BC:
	ldr r0, _081AD3E4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081AD3CA:
	ldr r2, _081AD3E8 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x28
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081AD3EC
	adds r0, #4
	b _081AD3F8
	.align 2, 0
_081AD3E4: .4byte 0x030046A4
_081AD3E8: .4byte 0x00000256
_081AD3EC:
	ldr r0, _081AD40C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081AD3F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081AD410
	cmp r2, #2
	beq _081AD414
	b _081AD418
	.align 2, 0
_081AD40C: .4byte 0x030046A4
_081AD410:
	ldrb r0, [r4, #4]
	b _081AD416
_081AD414:
	ldrb r0, [r4]
_081AD416:
	subs r1, r1, r0
_081AD418:
	ldr r3, _081AD430 @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _081AD434 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x2a]
	movs r6, #1
	str r6, [sp, #0x38]
	b _081AD478
	.align 2, 0
_081AD430: .4byte 0x00000472
_081AD434: .4byte 0x0000FFFF
_081AD438:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081AD49C @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081AD4A0 @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081AD4A4 @ =0x000004B4
	adds r1, r7, r6
	adds r0, r1, r0
	mov r6, sl
	strb r6, [r0]
	ldrb r2, [r2]
	movs r0, #1
	eors r0, r2
	adds r1, r1, r0
	strb r6, [r1]
	movs r0, #0
	str r0, [sp, #0x38]
	str r5, [sp, #0xf4]
	str r4, [sp, #0xf8]
	str r3, [sp, #0x100]
_081AD478:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081AD4C2
	bl VM_GetPC
	cmp r0, #0
	beq _081AD4A8
	bl Script_GetValue
	adds r4, r0, #0
	b _081AD4AA
	.align 2, 0
_081AD49C: .4byte 0x00000251
_081AD4A0: .4byte 0x00000252
_081AD4A4: .4byte 0x000004B4
_081AD4A8:
	movs r4, #0x30
_081AD4AA:
	bl VM_GetPC
	cmp r0, #0
	beq _081AD4BC
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081AD4BE
_081AD4BC:
	movs r5, #0x40
_081AD4BE:
	mov r8, r4
	b _081AD4C8
_081AD4C2:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081AD4C8:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081AD500
	bl VM_GetPC
	cmp r0, #0
	beq _081AD4E2
	bl Script_GetValue
	adds r6, r0, #0
	b _081AD4E4
_081AD4E2:
	movs r6, #0
_081AD4E4:
	bl VM_GetPC
	cmp r0, #0
	beq _081AD4F4
	bl Script_GetValue
	adds r1, r0, #0
	b _081AD4F6
_081AD4F4:
	movs r1, #0
_081AD4F6:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _081AD50A
_081AD500:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_081AD50A:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _081AD7CC @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x114]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0xec]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x1bc]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x1b8]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x104]
	lsls r4, r4, #0x10
	str r4, [sp, #0x58]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x68]
	lsls r6, r6, #0x10
	str r6, [sp, #0x70]
	lsls r5, r5, #0x10
	str r5, [sp, #0x64]
	ldr r4, _081AD7D0 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x110]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x48]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x160]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x88]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x164]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x168]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x15c]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x198]
	ldr r1, _081AD7D4 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x18c]
	ldr r2, _081AD7D8 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x190]
	ldr r3, _081AD7DC @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x194]
	ldr r4, _081AD7E0 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x1a8]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x1ac]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xa4]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xac]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xb4]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xc8]
	ldr r4, _081AD7E4 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0xcc]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xe4]
	ldr r6, _081AD7E8 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0xe8]
	ldr r1, _081AD7EC @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0xfc]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x108]
	ldr r3, _081AD7F0 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x10c]
	ldr r4, _081AD7F4 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x11c]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xf0]
	ldr r6, _081AD7F8 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0xa8]
	ldr r1, _081AD7FC @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x140]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x144]
	ldr r3, _081AD800 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xbc]
	ldr r4, _081AD804 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x148]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x130]
	ldr r6, _081AD808 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x124]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x134]
	ldr r2, _081AD80C @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x138]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x13c]
	ldr r4, _081AD810 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x14c]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x150]
	ldr r6, _081AD814 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0xe0]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x128]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x120]
	ldr r3, _081AD818 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x12c]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x118]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xd0]
	ldr r6, _081AD81C @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x154]
	ldr r1, _081AD820 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0xb0]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x158]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xdc]
	ldr r4, _081AD824 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0xb8]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xc0]
	ldr r6, _081AD828 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0xc4]
	ldr r1, _081AD82C @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0xd8]
	ldr r2, _081AD830 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0x1cc]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x1c0]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x1c4]
	ldr r5, _081AD834 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x1a4]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x170]
	ldr r1, _081AD838 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x174]
	ldr r2, _081AD83C @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x178]
	ldr r3, _081AD840 @ =0x00000484
	adds r3, r7, r3
	str r3, [sp, #0x19c]
	ldr r4, _081AD844 @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x180]
	ldr r5, _081AD848 @ =0x0000046D
	adds r5, r7, r5
	str r5, [sp, #0x184]
	ldr r6, _081AD84C @ =0x0000046B
	adds r6, r7, r6
	str r6, [sp, #0x17c]
	ldr r1, _081AD850 @ =0x00000553
	adds r1, r7, r1
	str r1, [sp, #0x50]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xa0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x1d0]
	movs r4, #0x92
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x1a0]
	adds r5, r7, #0
	adds r5, #0xd8
	str r5, [sp, #0x16c]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x3c]
	movs r1, #0xab
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x5c]
	ldr r2, _081AD854 @ =0x00000554
	adds r2, r7, r2
	str r2, [sp, #0x54]
	movs r3, #0xaa
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x40]
	ldr r4, _081AD858 @ =0x00000551
	adds r4, r7, r4
	str r4, [sp, #0x44]
	ldr r5, _081AD85C @ =0x00000552
	adds r5, r7, r5
	str r5, [sp, #0x4c]
	movs r1, #0xca
	lsls r1, r1, #4
	ldr r6, [sp, #0x30]
	adds r1, r6, r1
	str r1, [sp, #0xd4]
	ldr r2, _081AD860 @ =0x00000572
	adds r2, r7, r2
	str r2, [sp, #0x9c]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x1c8]
	movs r4, #0xae
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x98]
	ldr r5, _081AD864 @ =0x0000055C
	adds r5, r7, r5
	str r5, [sp, #0x6c]
	movs r6, #0xac
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x74]
	ldr r1, _081AD868 @ =0x00000564
	adds r1, r7, r1
	str r1, [sp, #0x7c]
	ldr r2, _081AD86C @ =0x00000565
	adds r2, r7, r2
	str r2, [sp, #0x80]
	ldr r3, _081AD870 @ =0x00000566
	adds r3, r7, r3
	str r3, [sp, #0x84]
	ldr r4, _081AD874 @ =0x00000567
	adds r4, r7, r4
	str r4, [sp, #0x8c]
	movs r5, #0xad
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x90]
	ldr r6, _081AD878 @ =0x0000056C
	adds r6, r7, r6
	str r6, [sp, #0x94]
	cmp r0, #0
	bne _081AD79E
	b _081AD8D4
_081AD79E:
	movs r0, #0
	mov sl, r0
	movs r1, #0x8d
	lsls r1, r1, #2
	adds r1, r1, r7
	mov sb, r1
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r2, r2, r7
	mov r8, r2
	movs r3, #0x8b
	lsls r3, r3, #2
	adds r5, r7, r3
	movs r6, #0x89
	lsls r6, r6, #2
	adds r4, r7, r6
_081AD7BE:
	bl VM_GetPC
	cmp r0, #0
	beq _081AD87C
	bl Script_GetValue
	b _081AD87E
	.align 2, 0
_081AD7CC: .4byte 0x0000025D
_081AD7D0: .4byte 0x0000025A
_081AD7D4: .4byte 0x0000047A
_081AD7D8: .4byte 0x0000047C
_081AD7DC: .4byte 0x0000047E
_081AD7E0: .4byte 0x000004A4
_081AD7E4: .4byte 0x000005A4
_081AD7E8: .4byte 0x000005C4
_081AD7EC: .4byte 0x000005CC
_081AD7F0: .4byte 0x000005D4
_081AD7F4: .4byte 0x000005DC
_081AD7F8: .4byte 0x00000584
_081AD7FC: .4byte 0x00000604
_081AD800: .4byte 0x0000021D
_081AD804: .4byte 0x0000060C
_081AD808: .4byte 0x000005E4
_081AD80C: .4byte 0x000005FC
_081AD810: .4byte 0x00000614
_081AD814: .4byte 0x000005BC
_081AD818: .4byte 0x000005EC
_081AD81C: .4byte 0x00000624
_081AD820: .4byte 0x0000058C
_081AD824: .4byte 0x00000594
_081AD828: .4byte 0x0000059C
_081AD82C: .4byte 0x000005B4
_081AD830: .4byte 0x00000543
_081AD834: .4byte 0x00000496
_081AD838: .4byte 0x00000469
_081AD83C: .4byte 0x0000046A
_081AD840: .4byte 0x00000484
_081AD844: .4byte 0x0000046C
_081AD848: .4byte 0x0000046D
_081AD84C: .4byte 0x0000046B
_081AD850: .4byte 0x00000553
_081AD854: .4byte 0x00000554
_081AD858: .4byte 0x00000551
_081AD85C: .4byte 0x00000552
_081AD860: .4byte 0x00000572
_081AD864: .4byte 0x0000055C
_081AD868: .4byte 0x00000564
_081AD86C: .4byte 0x00000565
_081AD870: .4byte 0x00000566
_081AD874: .4byte 0x00000567
_081AD878: .4byte 0x0000056C
_081AD87C:
	movs r0, #0x18
_081AD87E:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _081AD890
	bl Script_GetValue
	b _081AD892
_081AD890:
	movs r0, #0x18
_081AD892:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _081AD8A4
	bl Script_GetValue
	b _081AD8A6
_081AD8A4:
	movs r0, #0
_081AD8A6:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _081AD8B8
	bl Script_GetValue
	b _081AD8BA
_081AD8B8:
	movs r0, #0
_081AD8BA:
	strh r0, [r6]
	movs r0, #2
	add sb, r0
	movs r1, #4
	add r8, r1
	adds r5, #2
	adds r4, #2
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #3
	bgt _081AD8D4
	b _081AD7BE
_081AD8D4:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081AD920
	bl VM_GetPC
	cmp r0, #0
	beq _081AD8EE
	bl Script_GetValue
	adds r4, r0, #0
	b _081AD8F2
_081AD8EE:
	movs r4, #0x96
	lsls r4, r4, #1
_081AD8F2:
	bl VM_GetPC
	cmp r0, #0
	beq _081AD902
	bl Script_GetValue
	adds r6, r0, #0
	b _081AD906
_081AD902:
	movs r6, #0x96
	lsls r6, r6, #1
_081AD906:
	bl VM_GetPC
	cmp r0, #0
	beq _081AD914
	bl Script_GetValue
	b _081AD91A
_081AD914:
	movs r5, #0x96
	lsls r5, r5, #1
	adds r0, r5, #0
_081AD91A:
	ldr r1, [sp, #0xec]
	strh r0, [r1]
	b _081AD928
_081AD920:
	movs r4, #0
	movs r6, #0
	ldr r2, [sp, #0xec]
	strh r6, [r2]
_081AD928:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081AD940
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r3, [sp, #0x1b4]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_081AD940:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x1bc]
	strh r0, [r5]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x1b8]
	strh r0, [r1]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081ADA10
	bl VM_GetPC
	cmp r0, #0
	beq _081AD970
	bl Script_GetValue
	b _081AD972
_081AD970:
	movs r0, #0
_081AD972:
	ldr r2, [sp, #0x104]
	strh r0, [r2]
	ldrh r0, [r2]
	cmp r0, #0
	blt _081AD980
	asrs r1, r0, #1
	b _081AD986
_081AD980:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081AD986:
	ldr r3, _081AD99C @ =0x00000546
	adds r0, r7, r3
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081AD9A0
	bl Script_GetValue
	b _081AD9A2
	.align 2, 0
_081AD99C: .4byte 0x00000546
_081AD9A0:
	movs r0, #0
_081AD9A2:
	movs r5, #0xc3
	lsls r5, r5, #1
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081AD9B8
	bl Script_GetValue
	b _081AD9BA
_081AD9B8:
	movs r0, #0
_081AD9BA:
	ldr r2, _081AD9D0 @ =0x00000187
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081AD9D4
	bl Script_GetValue
	adds r1, r0, #0
	b _081AD9D6
	.align 2, 0
_081AD9D0: .4byte 0x00000187
_081AD9D4:
	movs r1, #0
_081AD9D6:
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081AD9EC
	bl Script_GetValue
	b _081AD9EE
_081AD9EC:
	movs r0, #0
_081AD9EE:
	movs r5, #0xc5
	lsls r5, r5, #1
	adds r1, r7, r5
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081ADA06
	bl Script_GetValue
	adds r1, r0, #0
	b _081ADA08
_081ADA06:
	movs r1, #0
_081ADA08:
	movs r2, #0xc6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081ADA10:
	ldr r3, [sp, #0x104]
	ldrh r1, [r3]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r4, [sp, #0x58]
	lsrs r2, r4, #0x10
	ldr r5, [sp, #0x68]
	lsrs r3, r5, #0x10
	ldr r6, [sp, #0x70]
	lsrs r0, r6, #0x10
	str r0, [sp]
	ldr r1, [sp, #0x64]
	lsrs r0, r1, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081ADA72
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r6, r7, r2
	bl VM_GetPC
	cmp r0, #0
	beq _081ADA58
	bl Script_GetValue
	b _081ADA5A
_081ADA58:
	movs r0, #0
_081ADA5A:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _081ADA6A
	bl Script_GetValue
	b _081ADA6C
_081ADA6A:
	movs r0, #0
_081ADA6C:
	ldr r3, _081ADAD4 @ =0x00000189
	adds r1, r7, r3
	strb r0, [r1]
_081ADA72:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r4, [sp, #0x110]
	strh r0, [r4]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081ADA96
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r5, [sp, #0x1b4]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081ADA96:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081ADAAE
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r6, [sp, #0x1b4]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
_081ADAAE:
	ldr r0, [sp, #0x48]
	lsrs r1, r0, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x34]
	add r2, sp, #0x28
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x188]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081ADAD8
	movs r0, #1
	b _081ADADA
	.align 2, 0
_081ADAD4: .4byte 0x00000189
_081ADAD8:
	movs r0, #0
_081ADADA:
	cmp r0, #0
	beq _081ADAEA
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _081ADB14 @ =FUN_080f48ac
	ldr r1, [sp, #0x34]
	bl FUN_0807f558
_081ADAEA:
	ldr r3, [sp, #0x114]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _081ADAF6
	ldr r1, [r7, #0x44]
_081ADAF6:
	ldr r0, [sp, #0x34]
	bl FUN_0823b46c
	ldr r4, [sp, #0x60]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _081ADB18
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x160]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _081ADB24
	.align 2, 0
_081ADB14: .4byte FUN_080f48ac
_081ADB18:
	ldr r0, [sp, #0x34]
	ldr r1, [sp, #0x160]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_081ADB24:
	ldr r5, [sp, #0x60]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081ADB72
	adds r0, r1, #0
	cmp r0, #0xb
	beq _081ADB72
	cmp r0, #0x16
	beq _081ADB72
	cmp r0, #0x14
	beq _081ADB72
	cmp r0, #9
	beq _081ADB72
	cmp r0, #0x19
	beq _081ADB72
	cmp r0, #0x1a
	beq _081ADB72
	cmp r0, #0xd
	beq _081ADB72
	cmp r0, #0x1b
	beq _081ADB72
	cmp r0, #0x1f
	beq _081ADB72
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0xf4]
	ldrb r2, [r6]
	ldr r0, [sp, #0xf8]
	ldrb r3, [r0]
	ldr r4, [sp, #0x100]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x34]
	bl FUN_0823b490
_081ADB72:
	movs r1, #8
	ldr r5, [sp, #0x188]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081ADB82
	movs r0, #1
	b _081ADB84
_081ADB82:
	movs r0, #0
_081ADB84:
	cmp r0, #0
	beq _081ADB92
	ldr r6, [sp, #0x88]
	ldr r0, [r6]
	ldr r1, [sp, #0x78]
	str r0, [r1]
	b _081ADBA4
_081ADB92:
	ldr r2, [sp, #0x88]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0x78]
	str r0, [r3]
_081ADBA4:
	ldrh r0, [r7]
	ldr r4, [sp, #0x164]
	strh r0, [r4]
	ldr r5, [sp, #0x15c]
	ldr r6, [sp, #0x168]
	str r5, [r6]
	ldr r0, [sp, #0x38]
	cmp r0, #0
	beq _081ADBCE
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #0x34]
	strb r0, [r1, #5]
_081ADBCE:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081ADCC0
	bl VM_GetPC
	cmp r0, #0
	beq _081ADBE6
	bl Script_GetValue
	b _081ADBE8
_081ADBE6:
	movs r0, #0
_081ADBE8:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _081ADBF8
	bl Script_GetValue
	b _081ADBFA
_081ADBF8:
	movs r0, #0
_081ADBFA:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _081ADC0A
	bl Script_GetValue
	b _081ADC0C
_081ADC0A:
	movs r0, #0
_081ADC0C:
	strh r0, [r7, #0xc]
	ldrh r0, [r7, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldr r3, [sp, #0x15c]
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081ADC34
	cmp r1, #0
	blt _081ADC34
	ldr r0, _081ADC38 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081ADC34
	ldr r0, _081ADC3C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081ADC40
_081ADC34:
	movs r1, #0
	b _081ADC4E
	.align 2, 0
_081ADC38: .4byte 0x030046A8
_081ADC3C: .4byte 0x030046AC
_081ADC40:
	ldr r0, _081ADC68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081ADC4E:
	ldr r4, _081ADC6C @ =0x00000256
	adds r0, r7, r4
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r5, [sp, #0x15c]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081ADC70
	adds r0, #4
	b _081ADC7C
	.align 2, 0
_081ADC68: .4byte 0x030046A4
_081ADC6C: .4byte 0x00000256
_081ADC70:
	ldr r0, _081ADC90 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ADC7C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081ADC94
	cmp r3, #2
	beq _081ADC98
	b _081ADC9C
	.align 2, 0
_081ADC90: .4byte 0x030046A4
_081ADC94:
	ldrb r0, [r5, #4]
	b _081ADC9A
_081ADC98:
	ldrb r0, [r5]
_081ADC9A:
	subs r2, r2, r0
_081ADC9C:
	ldr r5, _081ADCDC @ =0x00000472
	adds r1, r7, r5
	strh r2, [r1]
	ldrh r0, [r7, #0xa]
	subs r0, r0, r2
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r2, r7, r6
	strh r0, [r2]
	ldrh r0, [r1]
	strh r0, [r7, #0xa]
	ldr r0, [sp, #0x30]
	ldr r1, _081ADCE0 @ =0x00000CF8
	adds r2, r0, r1
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
_081ADCC0:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081ADCF2
	bl VM_GetPC
	cmp r0, #0
	beq _081ADCE4
	bl Script_GetValue
	adds r1, r0, #0
	b _081ADCEA
	.align 2, 0
_081ADCDC: .4byte 0x00000472
_081ADCE0: .4byte 0x00000CF8
_081ADCE4:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r2, #0
_081ADCEA:
	ldr r3, [sp, #0x30]
	ldr r4, _081ADD50 @ =0x00000C4A
	adds r0, r3, r4
	strh r1, [r0]
_081ADCF2:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x30]
	movs r6, #0xc4
	lsls r6, r6, #4
	adds r1, r5, r6
	movs r2, #0
	strh r0, [r1]
	ldr r1, _081ADD54 @ =0x00000C48
	adds r0, r5, r1
	strh r2, [r0]
	adds r0, r7, #0
	bl FUN_081ac088
	ldr r4, _081ADD58 @ =0x000001A5
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, [sp, #0x198]
	strh r0, [r2]
	ldr r3, [sp, #0x18c]
	strh r4, [r3]
	ldr r4, [sp, #0x190]
	strh r5, [r4]
	ldrh r0, [r2]
	adds r5, #0x73
	adds r0, r0, r5
	ldr r6, [sp, #0x194]
	strh r0, [r6]
	ldrh r1, [r3]
	ldrh r0, [r2]
	adds r1, r1, r0
	ldr r2, [sp, #0x114]
	ldrb r0, [r2]
	cmp r0, #0
	bne _081ADD5C
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081ADD68
	.align 2, 0
_081ADD50: .4byte 0x00000C4A
_081ADD54: .4byte 0x00000C48
_081ADD58: .4byte 0x000001A5
_081ADD5C:
	ldr r2, [r7, #0x44]
	ldr r0, _081ADDA0 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081ADD68:
	ldr r3, [sp, #0x114]
	ldrb r0, [r3]
	cmp r0, #1
	bne _081ADDB8
	ldr r4, [sp, #0x60]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _081ADDA4
	movs r0, #5
	bl FUN_080ecf60
	adds r4, r0, #1
	movs r0, #6
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #7
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #8
	bl FUN_080ecf60
	adds r4, r4, r0
	b _081ADDAE
	.align 2, 0
_081ADDA0: .4byte 0x03003584
_081ADDA4:
	ldr r5, [sp, #0x60]
	ldrb r0, [r5]
	bl FUN_080ecf60
	adds r4, r0, #1
_081ADDAE:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_081ADDB8:
	adds r0, r7, #0
	bl FUN_081ab06c
	adds r0, r7, #0
	bl FUN_081aaa60
	ldr r6, [sp, #0x30]
	ldr r0, _081ADFBC @ =0x00000CC4
	adds r3, r6, r0
	ldr r1, _081ADFC0 @ =0x00000CE8
	adds r4, r6, r1
	ldr r2, _081ADFC4 @ =FUN_081acf2c
	str r2, [sp, #0x1dc]
	ldr r5, _081ADFC8 @ =FUN_081abca4
	mov r8, r5
	ldr r6, _081ADFCC @ =FUN_081a7174
	mov sb, r6
	ldr r0, _081ADFD0 @ =FUN_081a6e24
	mov sl, r0
	ldr r1, _081ADFD4 @ =FUN_081a7074
	mov ip, r1
	movs r5, #0
	ldr r2, _081ADFD8 @ =FUN_080f62b0
	ldr r6, _081ADFDC @ =FUN_080f62ac
	str r6, [sp, #0x1d4]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x1b0]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x1a8]
	str r3, [r0]
	ldr r1, [sp, #0x1ac]
	str r4, [r1]
	ldr r3, [sp, #0x1dc]
	ldr r4, [sp, #0xa4]
	str r3, [r4]
	mov r6, r8
	ldr r0, [sp, #0xac]
	str r6, [r0]
	mov r1, sb
	ldr r3, [sp, #0xb4]
	str r1, [r3]
	mov r4, sl
	ldr r6, [sp, #0xc8]
	str r4, [r6]
	mov r0, ip
	ldr r1, [sp, #0xcc]
	str r0, [r1]
	ldr r3, _081ADFE0 @ =FUN_081a7178
	ldr r4, [sp, #0xe4]
	str r3, [r4]
	ldr r6, [sp, #0xe8]
	str r2, [r6]
	ldr r0, [sp, #0xfc]
	str r5, [r0]
	ldr r1, _081ADFE4 @ =FUN_081a8028
	ldr r2, [sp, #0x108]
	str r1, [r2]
	ldr r0, _081ADFE8 @ =FUN_080f44f4
	ldr r3, [sp, #0x10c]
	str r0, [r3]
	ldr r0, _081ADFEC @ =FUN_080f410c
	ldr r4, [sp, #0x11c]
	str r0, [r4]
	ldr r6, [sp, #0xf0]
	str r5, [r6]
	ldr r0, _081ADFF0 @ =FUN_081a72a4
	ldr r1, [sp, #0xa8]
	str r0, [r1]
	ldr r2, [sp, #0x1d4]
	ldr r3, [sp, #0x140]
	str r2, [r3]
	ldr r0, _081ADFF4 @ =FUN_080f0430
	ldr r4, [sp, #0x144]
	str r0, [r4]
	movs r0, #1
	ldr r6, [sp, #0xbc]
	strb r0, [r6]
	ldr r0, _081ADFF8 @ =0x085AD470
	ldr r1, [sp, #0x148]
	str r0, [r1]
	ldr r0, _081ADFFC @ =FUN_080e73c8
	ldr r2, [sp, #0x130]
	str r0, [r2]
	ldr r3, [sp, #0x124]
	str r5, [r3]
	ldr r4, [sp, #0x134]
	str r5, [r4]
	ldr r6, [sp, #0x138]
	str r5, [r6]
	ldr r0, [sp, #0x13c]
	str r5, [r0]
	ldr r1, [sp, #0x14c]
	str r5, [r1]
	ldr r0, _081AE000 @ =FUN_080f0320
	ldr r2, [sp, #0x150]
	str r0, [r2]
	ldr r0, _081AE004 @ =FUN_080eff14
	ldr r3, [sp, #0xe0]
	str r0, [r3]
	ldr r0, _081AE008 @ =FUN_080e72b0
	ldr r4, [sp, #0x128]
	str r0, [r4]
	ldr r6, _081AE00C @ =FUN_081a8010
	ldr r0, [sp, #0x120]
	str r6, [r0]
	ldr r0, _081AE010 @ =FUN_080f47c8
	ldr r1, [sp, #0x12c]
	str r0, [r1]
	ldr r0, _081AE014 @ =FUN_080f54e4
	ldr r2, [sp, #0x118]
	str r0, [r2]
	ldr r3, [sp, #0xd0]
	str r5, [r3]
	ldr r0, _081AE018 @ =FUN_080f6e64
	ldr r4, [sp, #0x154]
	str r0, [r4]
	ldr r0, _081AE01C @ =FUN_080f64f0
	ldr r6, [sp, #0xb0]
	str r0, [r6]
	ldr r0, _081AE020 @ =FUN_080f84d4
	ldr r1, [sp, #0x158]
	str r0, [r1]
	ldr r0, _081AE024 @ =FUN_080f624c
	ldr r2, [sp, #0xdc]
	str r0, [r2]
	ldr r0, _081AE028 @ =FUN_080f56ec
	ldr r3, [sp, #0xb8]
	str r0, [r3]
	ldr r0, _081AE02C @ =FUN_080f5b34
	ldr r4, [sp, #0xc0]
	str r0, [r4]
	ldr r0, _081AE030 @ =FUN_080f5fac
	ldr r6, [sp, #0xc4]
	str r0, [r6]
	ldr r0, [sp, #0xd8]
	str r5, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0x1cc]
	strb r0, [r1]
	ldr r2, _081AE034 @ =0x0000060C
	adds r1, r7, r2
	ldr r0, _081AE038 @ =0x085ADED8
	str r0, [r1]
	movs r3, #0xbf
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, _081AE03C @ =FUN_081ab110
	str r0, [r1]
	ldr r4, _081AE040 @ =0x000005FC
	adds r0, r7, r4
	str r5, [r0]
	ldr r6, _081AE044 @ =0x000005AC
	adds r1, r7, r6
	ldr r0, _081AE048 @ =FUN_081ac118
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081AE04C @ =FUN_081ac180
	str r0, [r1]
	subs r2, #4
	adds r1, r7, r2
	ldr r0, _081AE050 @ =FUN_081ac184
	str r0, [r1]
	subs r3, #0x6c
	adds r1, r7, r3
	ldr r0, _081AE054 @ =FUN_081acf14
	str r0, [r1]
	subs r4, #0x48
	adds r1, r7, r4
	ldr r0, _081AE058 @ =FUN_081ab92c
	str r0, [r1]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r0, r7, r6
	strh r5, [r0]
	ldr r1, _081AE05C @ =0x00100200
	ldr r2, [sp, #0x1b0]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #8
	ldr r3, [sp, #0x1b4]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	movs r6, #0x40
	ldr r4, [sp, #0x188]
	ldrh r1, [r4]
	adds r0, r6, #0
	orrs r0, r1
	strh r0, [r4]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0xaa
	lsls r0, r0, #2
	adds r4, r7, r0
	str r6, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r5, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	movs r1, #1
	str r1, [sp, #0x14]
	str r5, [sp, #0x18]
	adds r0, r4, #0
	ldr r1, [sp, #0x15c]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_08013ba8
	ldr r2, _081AE060 @ =0x0000044C
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _081AE064 @ =0x00001C1B
	adds r0, r4, #0
	movs r2, #6
	bl FUN_08013c94
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08013cb8
	adds r0, r4, #0
	bl FUN_080139a0
	ldr r3, _081AE068 @ =0x0000044D
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x1c0]
	strh r0, [r5]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081AE076
	movs r6, #0xce
	lsls r6, r6, #1
	adds r5, r7, r6
	movs r4, #4
_081ADFAE:
	bl VM_GetPC
	cmp r0, #0
	beq _081AE06C
	bl Script_GetValue
	b _081AE06E
	.align 2, 0
_081ADFBC: .4byte 0x00000CC4
_081ADFC0: .4byte 0x00000CE8
_081ADFC4: .4byte FUN_081acf2c
_081ADFC8: .4byte FUN_081abca4
_081ADFCC: .4byte FUN_081a7174
_081ADFD0: .4byte FUN_081a6e24
_081ADFD4: .4byte FUN_081a7074
_081ADFD8: .4byte FUN_080f62b0
_081ADFDC: .4byte FUN_080f62ac
_081ADFE0: .4byte FUN_081a7178
_081ADFE4: .4byte FUN_081a8028
_081ADFE8: .4byte FUN_080f44f4
_081ADFEC: .4byte FUN_080f410c
_081ADFF0: .4byte FUN_081a72a4
_081ADFF4: .4byte FUN_080f0430
_081ADFF8: .4byte 0x085AD470
_081ADFFC: .4byte FUN_080e73c8
_081AE000: .4byte FUN_080f0320
_081AE004: .4byte FUN_080eff14
_081AE008: .4byte FUN_080e72b0
_081AE00C: .4byte FUN_081a8010
_081AE010: .4byte FUN_080f47c8
_081AE014: .4byte FUN_080f54e4
_081AE018: .4byte FUN_080f6e64
_081AE01C: .4byte FUN_080f64f0
_081AE020: .4byte FUN_080f84d4
_081AE024: .4byte FUN_080f624c
_081AE028: .4byte FUN_080f56ec
_081AE02C: .4byte FUN_080f5b34
_081AE030: .4byte FUN_080f5fac
_081AE034: .4byte 0x0000060C
_081AE038: .4byte 0x085ADED8
_081AE03C: .4byte FUN_081ab110
_081AE040: .4byte 0x000005FC
_081AE044: .4byte 0x000005AC
_081AE048: .4byte FUN_081ac118
_081AE04C: .4byte FUN_081ac180
_081AE050: .4byte FUN_081ac184
_081AE054: .4byte FUN_081acf14
_081AE058: .4byte FUN_081ab92c
_081AE05C: .4byte 0x00100200
_081AE060: .4byte 0x0000044C
_081AE064: .4byte 0x00001C1B
_081AE068: .4byte 0x0000044D
_081AE06C:
	movs r0, #0
_081AE06E:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _081ADFAE
_081AE076:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x1c4]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x1a4]
	strh r0, [r3]
	cmp r2, #0
	beq _081AE0AE
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x1b0]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _081AE0AE
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_081AE0AE:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x188]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081AE0C0
	movs r0, #1
	b _081AE0C2
_081AE0C0:
	movs r0, #0
_081AE0C2:
	cmp r0, #0
	beq _081AE0D4
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x1b4]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081AE0D4:
	cmp r2, #1
	beq _081AE108
	movs r0, #0
	ldr r1, [sp, #0x170]
	strb r0, [r1]
	ldr r2, [sp, #0x174]
	strb r0, [r2]
	ldr r3, [sp, #0x178]
	strb r0, [r3]
	ldr r4, [sp, #0x19c]
	str r0, [r4]
	movs r1, #1
	ldr r5, [sp, #0x180]
	strb r1, [r5]
	ldr r6, [sp, #0xcc]
	ldr r2, [r6]
	ldr r3, [sp, #0x184]
	strb r1, [r3]
	ldr r4, [sp, #0x17c]
	strb r0, [r4]
	ldr r5, [sp, #0x50]
	strb r0, [r5]
	ldr r6, [sp, #0xa0]
	str r2, [r6]
	ldr r1, [sp, #0x1d0]
	strh r0, [r1]
_081AE108:
	movs r1, #2
	ldr r2, [sp, #0x188]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081AE118
	movs r0, #1
	b _081AE11A
_081AE118:
	movs r0, #0
_081AE11A:
	cmp r0, #0
	beq _081AE134
	ldr r0, _081AE130 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x1a0]
	strh r0, [r4]
	b _081AE13E
	.align 2, 0
_081AE130: .4byte 0x030046A0
_081AE134:
	ldr r0, [sp, #0x15c]
	bl FUN_08241574
	ldr r5, [sp, #0x1a0]
	strh r0, [r5]
_081AE13E:
	movs r1, #0x40
	ldr r6, [sp, #0x188]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081AE14E
	movs r0, #1
	b _081AE150
_081AE14E:
	movs r0, #0
_081AE150:
	cmp r0, #0
	beq _081AE15E
	ldr r0, _081AE184 @ =0xFFFFFEFF
	ldr r2, [sp, #0x16c]
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_081AE15E:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _081AE192
	ldr r0, _081AE188 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x1a0]
	ldrh r4, [r4]
	cmp r0, r4
	bne _081AE18C
	movs r0, #1
	b _081AE18E
	.align 2, 0
_081AE184: .4byte 0xFFFFFEFF
_081AE188: .4byte 0x030046A0
_081AE18C:
	movs r0, #0
_081AE18E:
	cmp r0, #0
	bne _081AE19A
_081AE192:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_081AE19A:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0x114]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081AE282
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081AE1DC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081AE1E4
_081AE1DC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081AE1E4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081AE208
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081AE210
_081AE208:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081AE210:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081AE248 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081AE28C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081AE24C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081AE240
	ldrb r0, [r4, #5]
_081AE240:
	subs r0, #1
	strh r0, [r4, #8]
	b _081AE25C
	.align 2, 0
_081AE248: .4byte 0x0000FFFF
_081AE24C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081AE25C
	strh r1, [r4, #8]
_081AE25C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081AE28C
	movs r0, #1
	strb r0, [r4, #7]
	b _081AE28C
_081AE282:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_081AE28C:
	movs r0, #0
	ldr r3, [sp, #0x3c]
	str r0, [r3]
	ldr r0, _081AE2A4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081AE2A8
	movs r0, #1
	b _081AE2AA
	.align 2, 0
_081AE2A4: .4byte 0x030047A4
_081AE2A8:
	movs r0, #0
_081AE2AA:
	cmp r0, #0
	bne _081AE2EA
	ldr r4, [sp, #0x60]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081AE2D2
	adds r0, r1, #0
	cmp r0, #7
	beq _081AE2D2
	cmp r0, #6
	beq _081AE2D2
	cmp r0, #0x15
	beq _081AE2D2
	cmp r0, #0x14
	beq _081AE2D2
	cmp r0, #0x17
	bne _081AE2EA
_081AE2D2:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x188]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081AE2EA:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_081a9710
	adds r0, r7, #0
	bl FUN_081aceb4
	ldr r1, _081AE434 @ =0x0000D636
	ldr r2, _081AE438 @ =0x0000C102
	ldrb r3, [r7, #5]
	adds r0, r7, #0
	bl FUN_081aa2b8
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x15c]
	bl FUN_081ab024
	adds r0, r7, #0
	bl FUN_081abb80
	adds r0, r7, #0
	bl FUN_081a97a4
	ldr r2, _081AE43C @ =FUN_080e6794
	movs r0, #0xe
	movs r1, #0
	movs r5, #1
	ldr r6, [sp, #0x184]
	strb r5, [r6]
	ldr r3, [sp, #0x17c]
	strb r1, [r3]
	ldr r4, [sp, #0x50]
	strb r0, [r4]
	ldr r6, [sp, #0xa0]
	str r2, [r6]
	movs r4, #0
	ldr r0, [sp, #0x1d0]
	strh r1, [r0]
	movs r0, #3
	ldr r2, [sp, #0x170]
	strb r0, [r2]
	ldr r3, [sp, #0x174]
	strb r4, [r3]
	ldr r6, [sp, #0x178]
	strb r4, [r6]
	ldr r0, [sp, #0x19c]
	str r1, [r0]
	ldr r1, [sp, #0x180]
	strb r5, [r1]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r1, [r0]
	movs r2, #6
	movs r0, #0x78
	ldr r3, [sp, #0x54]
	str r0, [r3]
	ldr r6, [sp, #0x5c]
	str r1, [r6]
	ldr r0, [sp, #0x40]
	strb r4, [r0]
	ldr r1, [sp, #0x44]
	strb r4, [r1]
	ldr r3, [sp, #0x4c]
	strb r2, [r3]
	ldr r6, _081AE440 @ =0x00000472
	adds r4, r7, r6
	ldrh r0, [r4]
	strh r0, [r7, #0xa]
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r2, [sp, #0xd4]
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, [sp, #0x15c]
	bl FUN_081acd70
	ldr r3, _081AE444 @ =0xFFFFFE00
	adds r0, r3, #0
	ldrh r4, [r4]
	adds r0, r0, r4
	strh r0, [r7, #0xa]
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x15c]
	bl FUN_081ab024
	ldr r0, [sp, #0x30]
	bl FUN_081aa5c0
	ldr r1, [r7, #0x44]
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	ldr r4, [sp, #0x16c]
	ldrh r0, [r4, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r4, #6]
	adds r0, r7, #0
	bl FUN_081ac7f8
	ldr r5, [sp, #0x188]
	ldrh r0, [r5]
	ldr r6, [sp, #0x9c]
	strh r0, [r6]
	ldr r1, [sp, #0x1c8]
	ldrh r0, [r1]
	ldr r2, [sp, #0x98]
	strh r0, [r2]
	ldr r3, [sp, #0x1b0]
	ldr r0, [r3]
	ldr r4, [sp, #0x6c]
	str r0, [r4]
	ldr r5, [sp, #0x1b4]
	ldr r0, [r5]
	ldr r6, [sp, #0x74]
	str r0, [r6]
	ldrb r0, [r7, #5]
	ldr r1, [sp, #0x7c]
	strb r0, [r1]
	ldr r2, [sp, #0x170]
	ldrb r0, [r2]
	ldr r3, [sp, #0x80]
	strb r0, [r3]
	ldr r4, [sp, #0x174]
	ldrb r0, [r4]
	ldr r5, [sp, #0x84]
	strb r0, [r5]
	ldr r6, [sp, #0x178]
	ldrb r0, [r6]
	ldr r1, [sp, #0x8c]
	strb r0, [r1]
	ldr r2, [sp, #0xa0]
	ldr r0, [r2]
	ldr r3, [sp, #0x90]
	str r0, [r3]
	ldr r4, [sp, #0x50]
	ldrb r0, [r4]
	ldr r5, [sp, #0x94]
	strb r0, [r5]
	ldr r6, _081AE448 @ =0x0000057C
	adds r1, r7, r6
	ldr r0, _081AE44C @ =FUN_080f09e0
	str r0, [r1]
	ldr r0, _081AE450 @ =0x0000061C
	adds r1, r7, r0
	ldr r0, _081AE454 @ =FUN_081acf68
	str r0, [r1]
	movs r2, #0xc4
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _081AE458 @ =FUN_081ad068
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081AE45C
	movs r0, #0
	b _081AE460
	.align 2, 0
_081AE434: .4byte 0x0000D636
_081AE438: .4byte 0x0000C102
_081AE43C: .4byte FUN_080e6794
_081AE440: .4byte 0x00000472
_081AE444: .4byte 0xFFFFFE00
_081AE448: .4byte 0x0000057C
_081AE44C: .4byte FUN_080f09e0
_081AE450: .4byte 0x0000061C
_081AE454: .4byte FUN_081acf68
_081AE458: .4byte FUN_081ad068
_081AE45C:
	movs r0, #1
	rsbs r0, r0, #0
_081AE460:
	add sp, #0x1e0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyFlameSnake_Create
EnemyFlameSnake_Create: @ 0x081AE470
	push {r4, r5, lr}
	movs r5, #0xd0
	lsls r5, r5, #4
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081AE49E
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyFlameSnake_Init
	cmp r0, #0
	bge _081AE49E
	adds r0, r4, #0
	bl FUN_081ad068
	adds r0, r4, #0
	bl Free
_081AE49E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ae4a4
FUN_081ae4a4: @ 0x081AE4A4
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, [r5, #0x44]
	ldr r0, _081AE500 @ =0x03002BE0
	mov r2, sp
	adds r4, r1, #0
	adds r4, #0x1c
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r1, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _081AE504 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #5
	cmp r0, #0
	blt _081AE508
	asrs r1, r0, #0xc
	b _081AE50E
	.align 2, 0
_081AE500: .4byte 0x03002BE0
_081AE504: .4byte 0x085B0A08
_081AE508:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081AE50E:
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _081AE530 @ =0x085B0A08
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _081AE534
	asrs r1, r0, #0xc
	b _081AE53A
	.align 2, 0
_081AE530: .4byte 0x085B0A08
_081AE534:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081AE53A:
	movs r4, #0xe2
	lsls r4, r4, #1
	adds r3, r5, r4
	strh r1, [r3]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r0, #0
	beq _081AE560
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Div
	b _081AE576
_081AE560:
	cmp r1, #0
	beq _081AE574
	mov r0, sp
	movs r4, #4
	ldrsh r0, [r0, r4]
	movs r2, #0
	ldrsh r1, [r3, r2]
	bl Div
	b _081AE576
_081AE574:
	movs r0, #0
_081AE576:
	cmp r0, #0
	blt _081AE57E
	asrs r0, r0, #1
	b _081AE584
_081AE57E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081AE584:
	movs r3, #0xe1
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
