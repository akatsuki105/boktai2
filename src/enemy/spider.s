	.include "asm/macros.inc"

	.syntax unified
	
	.text

@ EnemyXXX_Create でファイル分けしているだけなので他の敵のコードも混じっているかもしれない

	thumb_func_start FUN_0812dce4
FUN_0812dce4: @ 0x0812DCE4
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0812DD18
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0812DD18
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, _0812DD20 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0812DD18:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0812DD20: .4byte 0xFEFFFFFF

	thumb_func_start FUN_0812dd24
FUN_0812dd24: @ 0x0812DD24
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sb, r0
	mov r8, r1
	adds r6, r2, #0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812DD46
	bl _0812EA56
_0812DD46:
	movs r1, #0x80
	lsls r1, r1, #5
	mov r2, sb
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	bne _0812DD56
	b _0812E300
_0812DD56:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0812DD68
	bl _0812EA56
_0812DD68:
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0812DD76
	b _0812E39E
_0812DD76:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r7, #4
	ldrh r0, [r0, #6]
	ands r0, r7
	cmp r0, #0
	beq _0812DD88
	bl _0812EA56
_0812DD88:
	movs r4, #1
	mov r0, sb
	ldrh r1, [r0, #6]
	adds r0, r1, #0
	ands r0, r4
	adds r3, r1, #0
	cmp r0, #0
	beq _0812DD9A
	b _0812E01E
_0812DD9A:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, sb
	ldr r1, [r2, #0x34]
	ands r0, r1
	adds r5, r1, #0
	cmp r0, #0
	bne _0812DDAE
	bl _0812EA56
_0812DDAE:
	ldr r2, _0812DE44 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0812DDC4
	bl _0812EA56
_0812DDC4:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0812DDD4
	bl _0812EA56
_0812DDD4:
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
	bne _0812DDEC
	b _0812DF36
_0812DDEC:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0812DE1A
	ands r3, r1
	cmp r3, #0
	beq _0812DE1A
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, sb
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0812DE14
	rsbs r1, r1, #0
_0812DE14:
	cmp r1, #0x20
	bgt _0812DE1A
	b _0812E45A
_0812DE1A:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _0812DE48 @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	mov r4, sb
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0812DE50
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812DE4C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812DEBE
	.align 2, 0
_0812DE44: .4byte 0x0000A007
_0812DE48: .4byte 0x0000048A
_0812DE4C: .4byte 0x03002BE0
_0812DE50:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812DE6C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812DE68 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812DEBE
	.align 2, 0
_0812DE68: .4byte 0x03002BE0
_0812DE6C:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0812DE88
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0812DE84 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812DEBE
	.align 2, 0
_0812DE84: .4byte 0x03002BE0
_0812DE88:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0812DEA4
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812DEA0 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812DEBE
	.align 2, 0
_0812DEA0: .4byte 0x03002BE0
_0812DEA4:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0812DEB6
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0812DEBE
_0812DEB6:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0812DEC0
_0812DEBE:
	movs r3, #1
_0812DEC0:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r0, sb
	ldr r1, [r0, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	str r5, [r0]
	subs r4, #4
	adds r0, r6, r4
	str r1, [r0]
	cmp r3, #0
	bne _0812DEE2
	bl _0812E6E8
_0812DEE2:
	movs r1, #2
	ldr r5, _0812DEF4 @ =0x00000474
	adds r0, r6, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812DEF8
	movs r0, #1
	b _0812DEFA
	.align 2, 0
_0812DEF4: .4byte 0x00000474
_0812DEF8:
	movs r0, #0
_0812DEFA:
	cmp r0, #0
	beq _0812DF14
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812DF10 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0812DF24
	.align 2, 0
_0812DF10: .4byte 0x03002BE0
_0812DF14:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0812DF24
	bl _0812E6E8
_0812DF24:
	ldr r1, [r0]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
	b _0812E6C0
_0812DF36:
	mov r0, r8
	strh r2, [r0, #0x3e]
	ldr r1, _0812DF60 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, sb
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0812DF68
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812DF64 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812DFD6
	.align 2, 0
_0812DF60: .4byte 0x0000048A
_0812DF64: .4byte 0x03002BE0
_0812DF68:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812DF84
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0812DF80 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812DFD6
	.align 2, 0
_0812DF80: .4byte 0x03002BE0
_0812DF84:
	adds r0, r2, #0
	ands r0, r7
	cmp r0, #0
	beq _0812DFA0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812DF9C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812DFD6
	.align 2, 0
_0812DF9C: .4byte 0x03002BE0
_0812DFA0:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0812DFBC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812DFB8 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812DFD6
	.align 2, 0
_0812DFB8: .4byte 0x03002BE0
_0812DFBC:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0812DFCE
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0812DFD6
_0812DFCE:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0812DFD8
_0812DFD6:
	movs r3, #1
_0812DFD8:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, sb
	ldr r1, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r5, [r0]
	ldr r5, _0812E00C @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	bne _0812DFF8
	b _0812E6E8
_0812DFF8:
	movs r1, #2
	ldr r2, _0812E010 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812E014
	movs r0, #1
	b _0812E016
	.align 2, 0
_0812E00C: .4byte 0x0000049C
_0812E010: .4byte 0x00000474
_0812E014:
	movs r0, #0
_0812E016:
	cmp r0, #0
	beq _0812E01C
	b _0812E68E
_0812E01C:
	b _0812E6A4
_0812E01E:
	ldr r0, _0812E030 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812E034
	movs r0, #1
	b _0812E036
	.align 2, 0
_0812E030: .4byte 0x030047A4
_0812E034:
	movs r0, #0
_0812E036:
	cmp r0, #0
	beq _0812E044
	mov r0, sb
	mov r1, r8
	bl FUN_08236640
	b _0812E04C
_0812E044:
	mov r0, sb
	mov r1, r8
	bl FUN_08236524
_0812E04C:
	mov r0, sb
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0812E084 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0812E088 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #0x10]
	cmp r0, #2
	bls _0812E07A
	cmp r2, #0x17
	bne _0812E08C
_0812E07A:
	mov r0, sb
	adds r0, #0x40
	ldrh r1, [r0]
	b _0812E0AE
	.align 2, 0
_0812E084: .4byte 0x0000048C
_0812E088: .4byte 0x000001DF
_0812E08C:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, sb
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0812E07A
	mov r0, sb
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _0812E0DC @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0812E0AE
	movs r1, #0
_0812E0AE:
	mov r0, r8
	adds r0, #0x40
	strh r1, [r0]
	adds r7, r0, #0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0812E0E8
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	ldrh r0, [r7]
	cmp r0, #0
	blt _0812E0E0
	asrs r0, r0, #1
	b _0812E0E6
	.align 2, 0
_0812E0DC: .4byte 0x00000187
_0812E0E0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0812E0E6:
	strh r0, [r7]
_0812E0E8:
	mov r2, sb
	ldrh r1, [r2, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0812E0FE
	mov r0, sb
	adds r0, #0x42
	ldrb r0, [r0]
	b _0812E170
_0812E0FE:
	mov r4, sp
	mov r3, sb
	adds r3, #0xc
	mov r2, r8
	adds r2, #0xc
	mov r5, r8
	ldrh r0, [r5, #0xc]
	mov r5, sb
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
	bne _0812E160
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0812E160
	ldr r2, _0812E150 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0812E154 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0812E158 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0812E15C @ =0x000001DD
	adds r1, r6, r4
	b _0812E174
	.align 2, 0
_0812E150: .4byte 0x030046B8
_0812E154: .4byte 0x000003FF
_0812E158: .4byte 0x0203B400
_0812E15C: .4byte 0x000001DD
_0812E160:
	mov r0, sp
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
_0812E170:
	ldr r3, _0812E194 @ =0x000001DD
	adds r1, r6, r3
_0812E174:
	strb r0, [r1]
	movs r3, #0
	mov r4, sb
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0812E19C
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0812E198 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812E20A
	.align 2, 0
_0812E194: .4byte 0x000001DD
_0812E198: .4byte 0x03002BE0
_0812E19C:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812E1B8
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812E1B4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812E20A
	.align 2, 0
_0812E1B4: .4byte 0x03002BE0
_0812E1B8:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0812E1D4
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E1D0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812E20A
	.align 2, 0
_0812E1D0: .4byte 0x03002BE0
_0812E1D4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0812E1F0
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0812E1EC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812E20A
	.align 2, 0
_0812E1EC: .4byte 0x03002BE0
_0812E1F0:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0812E202
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0812E20A
_0812E202:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0812E20C
_0812E20A:
	movs r3, #1
_0812E20C:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, sb
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _0812E240 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0812E2A8
	movs r1, #2
	ldr r2, _0812E244 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812E248
	movs r0, #1
	b _0812E24A
	.align 2, 0
_0812E240: .4byte 0x0000049C
_0812E244: .4byte 0x00000474
_0812E248:
	movs r0, #0
_0812E24A:
	cmp r0, #0
	beq _0812E264
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E260 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0812E270
	.align 2, 0
_0812E260: .4byte 0x03002BE0
_0812E264:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0812E2A8
_0812E270:
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
_0812E2A8:
	ldr r4, [sp, #0x10]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0812E2DC
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0812E2DC
	ldr r0, _0812E2F4 @ =0x0000024E
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
	bls _0812E2DC
	strh r1, [r2]
_0812E2DC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0812E2F8 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _0812E2FC @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812E2F2
	b _0812EA00
_0812E2F2:
	b _0812EA10
	.align 2, 0
_0812E2F4: .4byte 0x0000024E
_0812E2F8: .4byte 0x030046A0
_0812E2FC: .4byte 0x00000934
_0812E300:
	mov r0, sb
	movs r1, #0xe
	ldrsh r3, [r0, r1]
	mov r2, r8
	movs r1, #0xe
	ldrsh r0, [r2, r1]
	subs r3, r3, r0
	asrs r3, r3, #1
	mov r2, sb
	ldrh r1, [r2, #0xc]
	subs r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0812E3B8 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	mov r1, sb
	ldrh r0, [r1, #0x10]
	subs r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r2, r5
	adds r5, r2, #0
	orrs r5, r0
	mov r2, r8
	movs r3, #0xc
	ldrsh r7, [r2, r3]
	movs r0, #0x1c
	ldrsh r3, [r2, r0]
	adds r1, r7, r3
	lsls r0, r4, #0x10
	asrs r2, r0, #0x10
	cmp r1, r2
	bgt _0812E34A
	b _0812EA56
_0812E34A:
	subs r0, r7, r3
	cmp r0, r2
	blt _0812E352
	b _0812EA56
_0812E352:
	mov r1, r8
	movs r2, #0x10
	ldrsh r7, [r1, r2]
	movs r0, #0x20
	ldrsh r3, [r1, r0]
	adds r1, r7, r3
	lsls r0, r5, #0x10
	asrs r2, r0, #0x10
	cmp r1, r2
	bgt _0812E368
	b _0812EA56
_0812E368:
	subs r0, r7, r3
	cmp r0, r2
	blt _0812E370
	b _0812EA56
_0812E370:
	mov r1, sb
	ldr r3, [r1, #0x48]
	cmp r3, #0
	beq _0812E382
	ldr r2, [r1, #0x4c]
	mov r0, sb
	mov r1, r8
	bl _call_via_r3
_0812E382:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _0812E392
	b _0812EA56
_0812E392:
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _0812E3C0
_0812E39E:
	ldr r4, _0812E3BC @ =0x0000048C
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812E3AA
	b _0812EA56
_0812E3AA:
	movs r1, #0
	mov r5, r8
	strh r2, [r5, #0x3e]
	mov r0, r8
	adds r0, #0x43
	strb r1, [r0]
	b _0812EA56
	.align 2, 0
_0812E3B8: .4byte 0xFFFF0000
_0812E3BC: .4byte 0x0000048C
_0812E3C0:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r7, #4
	ldrh r0, [r0, #6]
	ands r0, r7
	cmp r0, #0
	beq _0812E3D0
	b _0812EA56
_0812E3D0:
	movs r4, #1
	mov r0, sb
	ldrh r1, [r0, #6]
	adds r0, r1, #0
	ands r0, r4
	adds r3, r1, #0
	cmp r0, #0
	beq _0812E3E2
	b _0812E728
_0812E3E2:
	movs r0, #0x80
	lsls r0, r0, #7
	mov r2, sb
	ldr r1, [r2, #0x34]
	ands r0, r1
	adds r5, r1, #0
	cmp r0, #0
	bne _0812E3F4
	b _0812EA56
_0812E3F4:
	ldr r2, _0812E488 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0812E408
	b _0812EA56
_0812E408:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0812E416
	b _0812EA56
_0812E416:
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
	bne _0812E42E
	b _0812E5B0
_0812E42E:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0812E498
	ands r3, r1
	cmp r3, #0
	beq _0812E498
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	mov r0, sb
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0812E456
	rsbs r1, r1, #0
_0812E456:
	cmp r1, #0x20
	bgt _0812E498
_0812E45A:
	mov r3, sb
	ldrh r0, [r3, #0x3c]
	ldr r5, _0812E48C @ =0x000004BE
	adds r1, r6, r5
	strh r0, [r1]
	ldr r2, _0812E490 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0812E494 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0812EA56
	.align 2, 0
_0812E488: .4byte 0x0000A007
_0812E48C: .4byte 0x000004BE
_0812E490: .4byte 0x0000048C
_0812E494: .4byte 0x0000044E
_0812E498:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _0812E4C4 @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	mov r4, sb
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0812E4CC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812E4C8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812E53A
	.align 2, 0
_0812E4C4: .4byte 0x0000048A
_0812E4C8: .4byte 0x03002BE0
_0812E4CC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812E4E8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E4E4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812E53A
	.align 2, 0
_0812E4E4: .4byte 0x03002BE0
_0812E4E8:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0812E504
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0812E500 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812E53A
	.align 2, 0
_0812E500: .4byte 0x03002BE0
_0812E504:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0812E520
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812E51C @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812E53A
	.align 2, 0
_0812E51C: .4byte 0x03002BE0
_0812E520:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0812E532
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0812E53A
_0812E532:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0812E53C
_0812E53A:
	movs r3, #1
_0812E53C:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	mov r0, sb
	ldr r1, [r0, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	str r5, [r0]
	subs r4, #4
	adds r0, r6, r4
	str r1, [r0]
	cmp r3, #0
	bne _0812E55C
	b _0812E6E8
_0812E55C:
	movs r1, #2
	ldr r5, _0812E570 @ =0x00000474
	adds r0, r6, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812E574
	movs r0, #1
	b _0812E576
	.align 2, 0
_0812E570: .4byte 0x00000474
_0812E574:
	movs r0, #0
_0812E576:
	cmp r0, #0
	beq _0812E590
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812E58C @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0812E59E
	.align 2, 0
_0812E58C: .4byte 0x03002BE0
_0812E590:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _0812E59E
	b _0812E6E8
_0812E59E:
	ldr r1, [r0]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
	b _0812E6C0
_0812E5B0:
	mov r0, r8
	strh r2, [r0, #0x3e]
	ldr r1, _0812E5D8 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	mov r0, sb
	ldrh r2, [r0, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0812E5E0
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E5DC @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812E64E
	.align 2, 0
_0812E5D8: .4byte 0x0000048A
_0812E5DC: .4byte 0x03002BE0
_0812E5E0:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812E5FC
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0812E5F8 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812E64E
	.align 2, 0
_0812E5F8: .4byte 0x03002BE0
_0812E5FC:
	adds r0, r2, #0
	ands r0, r7
	cmp r0, #0
	beq _0812E618
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812E614 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812E64E
	.align 2, 0
_0812E614: .4byte 0x03002BE0
_0812E618:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0812E634
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E630 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812E64E
	.align 2, 0
_0812E630: .4byte 0x03002BE0
_0812E634:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0812E646
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0812E64E
_0812E646:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0812E650
_0812E64E:
	movs r3, #1
_0812E650:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, sb
	ldr r1, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r5, [r0]
	ldr r5, _0812E680 @ =0x0000049C
	adds r0, r6, r5
	str r1, [r0]
	cmp r3, #0
	beq _0812E6E8
	movs r1, #2
	ldr r2, _0812E684 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812E688
	movs r0, #1
	b _0812E68A
	.align 2, 0
_0812E680: .4byte 0x0000049C
_0812E684: .4byte 0x00000474
_0812E688:
	movs r0, #0
_0812E68A:
	cmp r0, #0
	beq _0812E6A4
_0812E68E:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E6A0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0812E6B0
	.align 2, 0
_0812E6A0: .4byte 0x03002BE0
_0812E6A4:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0812E6E8
_0812E6B0:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
_0812E6C0:
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
_0812E6E8:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0812E714
	ldr r5, _0812E720 @ =0x0000024E
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
	bls _0812E714
	strh r1, [r2]
_0812E714:
	ldr r5, _0812E724 @ =0x0000048C
	adds r1, r6, r5
	movs r0, #1
	strb r0, [r1]
	b _0812EA56
	.align 2, 0
_0812E720: .4byte 0x0000024E
_0812E724: .4byte 0x0000048C
_0812E728:
	ldr r0, _0812E73C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0812E740
	movs r0, #1
	b _0812E742
	.align 2, 0
_0812E73C: .4byte 0x030047A4
_0812E740:
	movs r0, #0
_0812E742:
	cmp r0, #0
	beq _0812E750
	mov r0, sb
	mov r1, r8
	bl FUN_08236640
	b _0812E758
_0812E750:
	mov r0, sb
	mov r1, r8
	bl FUN_08236524
_0812E758:
	mov r0, sb
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0812E790 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0812E794 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #0x10]
	cmp r0, #2
	bls _0812E786
	cmp r2, #0x17
	bne _0812E798
_0812E786:
	mov r0, sb
	adds r0, #0x40
	ldrh r1, [r0]
	b _0812E7BA
	.align 2, 0
_0812E790: .4byte 0x0000048C
_0812E794: .4byte 0x000001DF
_0812E798:
	movs r1, #0x80
	lsls r1, r1, #0xb
	mov r4, sb
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0812E786
	mov r0, sb
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r5, _0812E7E8 @ =0x00000187
	adds r0, r6, r5
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0812E7BA
	movs r1, #0
_0812E7BA:
	mov r0, r8
	adds r0, #0x40
	strh r1, [r0]
	adds r7, r0, #0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0812E7F4
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	ldrh r0, [r7]
	cmp r0, #0
	blt _0812E7EC
	asrs r0, r0, #1
	b _0812E7F2
	.align 2, 0
_0812E7E8: .4byte 0x00000187
_0812E7EC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0812E7F2:
	strh r0, [r7]
_0812E7F4:
	mov r2, sb
	ldrh r1, [r2, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0812E814
	mov r0, sb
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r3, _0812E810 @ =0x000001DD
	adds r1, r6, r3
	b _0812E882
	.align 2, 0
_0812E810: .4byte 0x000001DD
_0812E814:
	add r3, sp, #8
	mov r5, sb
	adds r5, #0xc
	mov r4, r8
	adds r4, #0xc
	mov r0, r8
	ldrh r2, [r0, #0xc]
	mov r1, sb
	ldrh r0, [r1, #0xc]
	subs r2, r2, r0
	strh r2, [r3]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r5, #4]
	subs r0, r1, r0
	strh r0, [r3, #4]
	lsls r2, r2, #0x10
	cmp r2, #0
	bne _0812E870
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0812E870
	ldr r2, _0812E860 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0812E864 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _0812E868 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r3, _0812E86C @ =0x000001DD
	adds r1, r6, r3
	b _0812E882
	.align 2, 0
_0812E860: .4byte 0x030046B8
_0812E864: .4byte 0x000003FF
_0812E868: .4byte 0x0203B400
_0812E86C: .4byte 0x000001DD
_0812E870:
	movs r4, #0
	ldrsh r0, [r3, r4]
	add r1, sp, #8
	movs r5, #4
	ldrsh r1, [r1, r5]
	bl FUN_0823785c
	ldr r2, _0812E8A4 @ =0x000001DD
	adds r1, r6, r2
_0812E882:
	strb r0, [r1]
	movs r3, #0
	mov r4, sb
	ldrh r2, [r4, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0812E8AC
	movs r5, #0xec
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, _0812E8A8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0812E91A
	.align 2, 0
_0812E8A4: .4byte 0x000001DD
_0812E8A8: .4byte 0x03002BE0
_0812E8AC:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0812E8C8
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0812E8C4 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0812E91A
	.align 2, 0
_0812E8C4: .4byte 0x03002BE0
_0812E8C8:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0812E8E4
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E8E0 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0812E91A
	.align 2, 0
_0812E8E0: .4byte 0x03002BE0
_0812E8E4:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0812E900
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0812E8FC @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0812E91A
	.align 2, 0
_0812E8FC: .4byte 0x03002BE0
_0812E900:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0812E912
	movs r5, #0xec
	lsls r5, r5, #1
	adds r0, r6, r5
	str r3, [r0]
	b _0812E91A
_0812E912:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0812E91C
_0812E91A:
	movs r3, #1
_0812E91C:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	mov r2, sb
	ldr r1, [r2, #0x34]
	ldr r2, [r2, #0x38]
	movs r4, #0x93
	lsls r4, r4, #3
	adds r0, r6, r4
	str r1, [r0]
	ldr r5, _0812E950 @ =0x0000049C
	adds r0, r6, r5
	str r2, [r0]
	cmp r3, #0
	beq _0812E9B8
	movs r1, #2
	ldr r2, _0812E954 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812E958
	movs r0, #1
	b _0812E95A
	.align 2, 0
_0812E950: .4byte 0x0000049C
_0812E954: .4byte 0x00000474
_0812E958:
	movs r0, #0
_0812E95A:
	cmp r0, #0
	beq _0812E974
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0812E970 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0812E980
	.align 2, 0
_0812E970: .4byte 0x03002BE0
_0812E974:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0812E9B8
_0812E980:
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
_0812E9B8:
	ldr r4, [sp, #0x10]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0812E9EC
	movs r1, #0x80
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0812E9EC
	ldr r0, _0812EA04 @ =0x0000024E
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
	bls _0812E9EC
	strh r1, [r2]
_0812E9EC:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0812EA08 @ =0x030046A0
	ldr r0, [r0]
	ldr r5, _0812EA0C @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812EA10
_0812EA00:
	movs r0, #1
	b _0812EA12
	.align 2, 0
_0812EA04: .4byte 0x0000024E
_0812EA08: .4byte 0x030046A0
_0812EA0C: .4byte 0x00000934
_0812EA10:
	movs r0, #0
_0812EA12:
	ldr r1, _0812EA68 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0812EA2A
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	strh r0, [r7]
	strh r0, [r4]
	movs r0, #1
	ldr r3, [sp, #0x10]
	strb r0, [r3]
_0812EA2A:
	adds r0, r6, #0
	bl FUN_080e64e4
	mov r5, r8
	ldrh r0, [r5, #0x3e]
	strh r0, [r4]
	movs r0, #0xc4
	lsls r0, r0, #1
	adds r1, r6, r0
	mov r2, sb
	ldrh r0, [r2, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0812EA56:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812EA68: .4byte 0x0000048A

	thumb_func_start FUN_0812ea6c
FUN_0812ea6c: @ 0x0812EA6C
	push {lr}
	adds r2, r0, #0
	ldr r0, _0812EA8C @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812EA7E
	movs r0, #0
	strb r0, [r1]
_0812EA7E:
	adds r0, r2, #0
	movs r1, #1
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_0812EA8C: .4byte 0x0000046D

	thumb_func_start FUN_0812ea90
FUN_0812ea90: @ 0x0812EA90
	push {lr}
	adds r2, r0, #0
	ldr r0, _0812EAB0 @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812EAA2
	movs r0, #0
	strb r0, [r1]
_0812EAA2:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_0812EAB0: .4byte 0x0000046D

	thumb_func_start FUN_0812eab4
FUN_0812eab4: @ 0x0812EAB4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r7, r5, #0
	ldr r0, _0812EAD0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812EAD4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812EAD6
	.align 2, 0
_0812EAD0: .4byte 0x0000046D
_0812EAD4:
	movs r0, #0
_0812EAD6:
	cmp r0, #0
	bne _0812EADC
	b _0812ECDC
_0812EADC:
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r7, #5]
	ldrb r0, [r7, #5]
	adds r0, #0x20
	ands r0, r2
	asrs r0, r0, #6
	adds r2, r0, #1
	ands r2, r1
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	asrs r0, r0, #1
	cmp r2, r0
	beq _0812EB18
	subs r0, r0, r2
	cmp r0, #0
	bge _0812EB14
	rsbs r0, r0, #0
_0812EB14:
	cmp r0, #2
	beq _0812EB30
_0812EB18:
	ldr r2, _0812EB2C @ =0x0000046B
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	b _0812EDE8
	.align 2, 0
_0812EB2C: .4byte 0x0000046B
_0812EB30:
	cmp r2, #1
	beq _0812EB94
	cmp r2, #1
	bgt _0812EB3E
	cmp r2, #0
	beq _0812EB4A
	b _0812ECDC
_0812EB3E:
	cmp r2, #2
	beq _0812EC1C
	cmp r2, #3
	bne _0812EB48
	b _0812EC80
_0812EB48:
	b _0812ECDC
_0812EB4A:
	movs r2, #5
	ldr r1, _0812EB6C @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _0812EB74
	ldr r1, _0812EB70 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
	b _0812EBB2
	.align 2, 0
_0812EB6C: .4byte 0x0000025D
_0812EB70: .4byte 0x000004B7
_0812EB74:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	ldr r1, _0812EB8C @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0812EB90 @ =0x0000046E
	adds r4, r5, r0
	cmp r1, #5
	bne _0812EBF0
	b _0812EBE0
	.align 2, 0
_0812EB8C: .4byte 0x000004B7
_0812EB90: .4byte 0x0000046E
_0812EB94:
	movs r2, #5
	ldr r1, _0812EBBC @ =0x0000025D
	adds r0, r5, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _0812EBC8
	ldr r1, _0812EBC0 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #1
_0812EBB2:
	bl FUN_08236fac
	ldr r2, _0812EBC4 @ =0x0000046E
	adds r4, r5, r2
	b _0812EC0C
	.align 2, 0
_0812EBBC: .4byte 0x0000025D
_0812EBC0: .4byte 0x000004B7
_0812EBC4: .4byte 0x0000046E
_0812EBC8:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	movs r2, #6
	ldr r1, _0812EC14 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0812EC18 @ =0x0000046E
	adds r4, r5, r0
	cmp r1, #6
	bne _0812EBF0
_0812EBE0:
	ldrb r0, [r4]
	cmp r0, #0
	bne _0812EBF0
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0812ECDC
_0812EBF0:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
_0812EC0C:
	movs r0, #0
	strb r0, [r4]
	b _0812ECDC
	.align 2, 0
_0812EC14: .4byte 0x000004B7
_0812EC18: .4byte 0x0000046E
_0812EC1C:
	movs r1, #5
	ldr r2, _0812EC44 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812EC4C
	ldr r2, _0812EC48 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #5
	movs r3, #0
	bl FUN_08236fac
	b _0812EC72
	.align 2, 0
_0812EC44: .4byte 0x0000025D
_0812EC48: .4byte 0x000004B7
_0812EC4C:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldr r2, _0812EC78 @ =0x000004B7
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #6
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r2, #5
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0812EC72:
	ldr r0, _0812EC7C @ =0x0000046E
	adds r1, r5, r0
	b _0812ECD8
	.align 2, 0
_0812EC78: .4byte 0x000004B7
_0812EC7C: .4byte 0x0000046E
_0812EC80:
	movs r2, #5
	ldr r1, _0812ECA8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812ECB0
	ldr r1, _0812ECAC @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	movs r2, #4
	str r2, [sp]
	movs r2, #5
	movs r3, #1
	bl FUN_08236fac
	b _0812ECD4
	.align 2, 0
_0812ECA8: .4byte 0x0000025D
_0812ECAC: .4byte 0x000004B7
_0812ECB0:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	movs r2, #6
	ldr r1, _0812ED0C @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r2, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
_0812ECD4:
	ldr r2, _0812ED10 @ =0x0000046E
	adds r1, r5, r2
_0812ECD8:
	movs r0, #0
	strb r0, [r1]
_0812ECDC:
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	ldrh r0, [r0, #0xe]
	cmp r0, #0
	bne _0812ED3E
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	adds r2, r4, #0
	ldrb r0, [r7, #5]
	subs r1, r0, r2
	adds r3, r1, #0
	cmp r1, #0
	bge _0812ED04
	rsbs r3, r1, #0
_0812ED04:
	cmp r3, #0x40
	bgt _0812ED14
	strb r4, [r7, #5]
	b _0812ED3E
	.align 2, 0
_0812ED0C: .4byte 0x000004B7
_0812ED10: .4byte 0x0000046E
_0812ED14:
	cmp r0, r2
	bge _0812ED28
	adds r2, r1, #0
	cmp r1, #0
	bge _0812ED20
	rsbs r2, r1, #0
_0812ED20:
	cmp r2, #0x80
	ble _0812ED3A
	subs r0, #0x40
	b _0812ED3C
_0812ED28:
	cmp r0, r2
	ble _0812ED3E
	cmp r1, #0
	bge _0812ED32
	rsbs r1, r1, #0
_0812ED32:
	cmp r1, #0x80
	bgt _0812ED3A
	subs r0, #0x40
	b _0812ED3C
_0812ED3A:
	adds r0, #0x40
_0812ED3C:
	strb r0, [r7, #5]
_0812ED3E:
	ldr r1, _0812ED5C @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812ED64
	ldr r0, _0812ED60 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0812ED74
	.align 2, 0
_0812ED5C: .4byte 0x0000A02F
_0812ED60: .4byte 0x00000482
_0812ED64:
	ldr r1, _0812ED98 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0812ED74
	movs r0, #1
	strh r0, [r2]
_0812ED74:
	ldr r1, _0812ED9C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812EDA0
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
	b _0812EDB8
	.align 2, 0
_0812ED98: .4byte 0x00000482
_0812ED9C: .4byte 0x0000025D
_0812EDA0:
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
_0812EDB8:
	ldr r2, _0812EDF0 @ =0x0000046E
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0812EDE8
	ldr r0, _0812EDF4 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldrb r1, [r5, #5]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #6
	subs r0, #0x40
	strb r0, [r5, #5]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
_0812EDE8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812EDF0: .4byte 0x0000046E
_0812EDF4: .4byte 0x0000046B

	thumb_func_start FUN_0812edf8
FUN_0812edf8: @ 0x0812EDF8
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _0812EE10 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812EE14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812EE16
	.align 2, 0
_0812EE10: .4byte 0x0000046D
_0812EE14:
	movs r0, #0
_0812EE16:
	cmp r0, #0
	beq _0812EE52
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_08013984
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r3, _0812EF24 @ =0x00000474
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r5, #0x94
	lsls r5, r5, #1
	adds r2, r7, r5
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, r7, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
_0812EE52:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812EF1E
	ldr r3, _0812EF28 @ =0x0000044C
	adds r4, r7, r3
	ldrb r0, [r4]
	cmp r0, #0
	bne _0812EE7A
	movs r5, #0xaa
	lsls r5, r5, #2
	adds r0, r7, r5
	bl FUN_08013c70
	movs r0, #1
	strb r0, [r4]
_0812EE7A:
	ldr r0, _0812EF24 @ =0x00000474
	adds r2, r7, r0
	ldr r1, _0812EF2C @ =0xFFFFF7FF
	ldrh r0, [r2]
	ands r1, r0
	movs r4, #0
	movs r6, #0
	strh r1, [r2]
	movs r1, #0x94
	lsls r1, r1, #1
	adds r3, r7, r1
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r3, #6]
	adds r0, r1, #0
	ands r0, r2
	strh r0, [r3, #6]
	adds r2, r7, #0
	adds r2, #0xd8
	ldrh r0, [r2, #6]
	ands r1, r0
	strh r1, [r2, #6]
	ldr r2, _0812EF30 @ =0x000005A4
	adds r0, r7, r2
	ldr r3, [r0]
	movs r5, #5
	mov ip, r5
	movs r1, #0x14
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r7, r0
	ldr r5, _0812EF34 @ =0x00000554
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _0812EF38 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0812EF3C @ =0x00000552
	adds r0, r7, r3
	mov r5, ip
	strb r5, [r0]
	ldr r3, _0812EF40 @ =FUN_080e68d8
	movs r1, #0xe
	subs r2, #0xe4
	adds r0, r7, r2
	movs r2, #1
	strb r2, [r0]
	ldr r5, _0812EF44 @ =0x0000046B
	adds r0, r7, r5
	strb r4, [r0]
	adds r5, #0xe8
	adds r0, r7, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
	movs r1, #3
	subs r5, #0xeb
	adds r0, r7, r5
	strb r1, [r0]
	ldr r1, _0812EF48 @ =0x00000469
	adds r0, r7, r1
	strb r2, [r0]
	ldr r3, _0812EF4C @ =0x0000046A
	adds r0, r7, r3
	strb r4, [r0]
	adds r5, #0x1c
	adds r0, r7, r5
	str r6, [r0]
	adds r1, #3
	adds r0, r7, r1
	strb r2, [r0]
_0812EF1E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812EF24: .4byte 0x00000474
_0812EF28: .4byte 0x0000044C
_0812EF2C: .4byte 0xFFFFF7FF
_0812EF30: .4byte 0x000005A4
_0812EF34: .4byte 0x00000554
_0812EF38: .4byte 0x00000551
_0812EF3C: .4byte 0x00000552
_0812EF40: .4byte FUN_080e68d8
_0812EF44: .4byte 0x0000046B
_0812EF48: .4byte 0x00000469
_0812EF4C: .4byte 0x0000046A

	thumb_func_start FUN_0812ef50
FUN_0812ef50: @ 0x0812EF50
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	mov r8, r5
	ldr r2, _0812F030 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812EF72
	movs r0, #0
	strb r0, [r1]
_0812EF72:
	adds r0, r5, #0
	movs r1, #0xe
	bl FUN_080ef86c
	ldr r3, _0812F034 @ =0x0000065E
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bgt _0812EF88
	b _0812F192
_0812EF88:
	adds r3, #2
	adds r2, r4, r3
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r7, #0
	strh r0, [r2]
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrh r6, [r0]
	cmp r6, #0
	bne _0812F058
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	mov r1, r8
	bl FUN_080db290
	cmp r0, #0
	blt _0812F058
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r4, #7
	mov r8, r4
	movs r1, #0x3c
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r4, _0812F038 @ =0x00000554
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r7, [r0]
	ldr r2, _0812F03C @ =0x00000551
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _0812F040 @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	ldr r3, _0812F044 @ =FUN_080e68d8
	movs r1, #0xe
	subs r2, #0xe4
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	ldr r4, _0812F048 @ =0x0000046B
	adds r0, r5, r4
	strb r7, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r6, [r0]
	movs r1, #3
	subs r4, #0xeb
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _0812F04C @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r3, _0812F050 @ =0x0000046A
	adds r0, r5, r3
	strb r7, [r0]
	adds r4, #0x1c
	adds r0, r5, r4
	str r6, [r0]
	ldr r6, _0812F054 @ =0x0000046C
	adds r0, r5, r6
	b _0812F190
	.align 2, 0
_0812F030: .4byte 0x0000046D
_0812F034: .4byte 0x0000065E
_0812F038: .4byte 0x00000554
_0812F03C: .4byte 0x00000551
_0812F040: .4byte 0x00000552
_0812F044: .4byte FUN_080e68d8
_0812F048: .4byte 0x0000046B
_0812F04C: .4byte 0x00000469
_0812F050: .4byte 0x0000046A
_0812F054: .4byte 0x0000046C
_0812F058:
	ldr r2, _0812F0F4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0812F0F8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0812F0FC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r6, r0, #3
	movs r7, #3
	ands r6, r7
	cmp r6, #0
	bne _0812F11C
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, [r0]
	movs r4, #7
	mov r8, r4
	movs r1, #0x3c
	movs r0, #0xab
	lsls r0, r0, #3
	adds r2, r5, r0
	ldr r4, _0812F100 @ =0x00000554
	adds r0, r5, r4
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r6, [r0]
	ldr r2, _0812F104 @ =0x00000551
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _0812F108 @ =0x00000552
	adds r0, r5, r3
	mov r4, r8
	strb r4, [r0]
	ldr r3, _0812F10C @ =FUN_080e68d8
	movs r2, #0xe
	subs r1, #0xe3
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _0812F110 @ =0x0000046B
	adds r0, r5, r4
	strb r6, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r2, #0
	strh r6, [r0]
	subs r4, #0xeb
	adds r0, r5, r4
	strb r7, [r0]
	ldr r3, _0812F114 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _0812F118 @ =0x00000484
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	b _0812F192
	.align 2, 0
_0812F0F4: .4byte 0x030046B8
_0812F0F8: .4byte 0x000003FF
_0812F0FC: .4byte 0x0203B400
_0812F100: .4byte 0x00000554
_0812F104: .4byte 0x00000551
_0812F108: .4byte 0x00000552
_0812F10C: .4byte FUN_080e68d8
_0812F110: .4byte 0x0000046B
_0812F114: .4byte 0x00000469
_0812F118: .4byte 0x00000484
_0812F11C:
	ldr r4, _0812F19C @ =0x000005A4
	adds r0, r5, r4
	ldr r3, [r0]
	movs r4, #5
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r5, r6
	subs r6, #4
	adds r0, r5, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0812F1A0 @ =0x00000551
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _0812F1A4 @ =0x00000552
	adds r0, r5, r3
	strb r4, [r0]
	ldr r4, _0812F1A8 @ =FUN_080e68d8
	movs r3, #0xe
	subs r6, #0xe7
	adds r0, r5, r6
	movs r2, #1
	strb r2, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r3, #0
	strh r1, [r0]
	subs r6, #0xeb
	adds r0, r5, r6
	strb r7, [r0]
	ldr r4, _0812F1AC @ =0x00000469
	adds r0, r5, r4
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	ldr r3, _0812F1B0 @ =0x00000484
	adds r0, r5, r3
	str r1, [r0]
	adds r4, #3
	adds r0, r5, r4
_0812F190:
	strb r2, [r0]
_0812F192:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812F19C: .4byte 0x000005A4
_0812F1A0: .4byte 0x00000551
_0812F1A4: .4byte 0x00000552
_0812F1A8: .4byte FUN_080e68d8
_0812F1AC: .4byte 0x00000469
_0812F1B0: .4byte 0x00000484

	thumb_func_start FUN_0812f1b4
FUN_0812f1b4: @ 0x0812F1B4
	bx lr
	.align 2, 0

	thumb_func_start FUN_0812f1b8
FUN_0812f1b8: @ 0x0812F1B8
	bx lr
	.align 2, 0

	thumb_func_start FUN_0812f1bc
FUN_0812f1bc: @ 0x0812F1BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	mov r8, r1
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	adds r7, r5, #0
	ldr r2, _0812F1EC @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812F1F0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812F1F2
	.align 2, 0
_0812F1EC: .4byte 0x0000046D
_0812F1F0:
	movs r0, #0
_0812F1F2:
	cmp r0, #0
	beq _0812F22C
	movs r0, #0x80
	lsls r0, r0, #1
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080ef86c
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _0812F32C @ =0xFFFFBFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [r1]
_0812F22C:
	ldrh r0, [r4, #8]
	cmp r0, #3
	bne _0812F270
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	bne _0812F270
	movs r0, #0x8a
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r0, r6, r4
	ldr r2, [r0]
	cmp r2, #0
	beq _0812F270
	movs r1, #0x98
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r3, _0812F330 @ =0x00000226
	adds r1, r5, r3
	ldrh r3, [r1]
	ldr r4, _0812F334 @ =0x0000022E
	adds r1, r5, r4
	ldrh r1, [r1]
	str r1, [sp]
	adds r4, #8
	adds r1, r5, r4
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r7, #0
	bl FUN_081e8ab8
_0812F270:
	ldr r1, _0812F338 @ =0x0000046E
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0812F31E
	mov r2, r8
	cmp r2, #0x3c
	ble _0812F31E
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r6, r5, r3
	ldr r1, _0812F33C @ =0xFFFFFEFF
	ldrh r0, [r6]
	ands r1, r0
	movs r7, #0
	movs r4, #0
	strh r1, [r6]
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r7, [r0]
	ldr r3, _0812F340 @ =0x00000469
	adds r0, r5, r3
	strb r7, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r4, [r0]
	ldr r1, _0812F344 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r0, [r0]
	mov r8, r0
	movs r2, #0x1a
	subs r3, #0x17
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0812F348 @ =0x0000046B
	adds r0, r5, r1
	strb r7, [r0]
	adds r3, #0xe6
	adds r0, r5, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r2, r8
	str r2, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_08130eec
	adds r0, r5, #0
	bl FUN_080e6204
	ldr r4, _0812F34C @ =0x000001DF
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #2
	beq _0812F308
	movs r0, #4
	ldr r1, _0812F350 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0812F308:
	movs r0, #0x80
	ldrh r1, [r6]
	orrs r0, r1
	strh r0, [r6]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _0812F354 @ =0x0000024E
	adds r0, r5, r3
	strh r1, [r0]
_0812F31E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812F32C: .4byte 0xFFFFBFFF
_0812F330: .4byte 0x00000226
_0812F334: .4byte 0x0000022E
_0812F338: .4byte 0x0000046E
_0812F33C: .4byte 0xFFFFFEFF
_0812F340: .4byte 0x00000469
_0812F344: .4byte 0x0000046C
_0812F348: .4byte 0x0000046B
_0812F34C: .4byte 0x000001DF
_0812F350: .4byte 0x00000222
_0812F354: .4byte 0x0000024E

	thumb_func_start FUN_0812f358
FUN_0812f358: @ 0x0812F358
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _0812F3E4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812F36A
	movs r0, #0
	strb r0, [r1]
_0812F36A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
	ldr r1, _0812F3E8 @ =0x0000024E
	adds r0, r4, r1
	ldrh r5, [r0]
	cmp r5, #0
	bne _0812F3DC
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	movs r0, #0x81
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r3, #0
	strh r0, [r2]
	movs r1, #7
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r4, r6
	strb r3, [r0]
	ldr r2, _0812F3EC @ =0x00000469
	adds r0, r4, r2
	strb r3, [r0]
	adds r6, #2
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _0812F3F0 @ =0x00000484
	adds r0, r4, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	movs r6, #0xb4
	lsls r6, r6, #3
	adds r0, r4, r6
	ldr r2, [r0]
	ldr r6, _0812F3E4 @ =0x0000046D
	adds r0, r4, r6
	strb r1, [r0]
	subs r6, #2
	adds r0, r4, r6
	strb r3, [r0]
	ldr r3, _0812F3F4 @ =0x00000553
	adds r0, r4, r3
	strb r1, [r0]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r0, r4, r6
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_0812F3DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812F3E4: .4byte 0x0000046D
_0812F3E8: .4byte 0x0000024E
_0812F3EC: .4byte 0x00000469
_0812F3F0: .4byte 0x00000484
_0812F3F4: .4byte 0x00000553

	thumb_func_start FUN_0812f3f8
FUN_0812f3f8: @ 0x0812F3F8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, [r5, #0x44]
	adds r4, r0, #0
	adds r4, #0x48
	ldr r0, _0812F418 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812F41C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812F41E
	.align 2, 0
_0812F418: .4byte 0x0000046D
_0812F41C:
	movs r0, #0
_0812F41E:
	cmp r0, #0
	beq _0812F458
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r3, #0xcc
	lsls r3, r3, #3
	adds r1, r1, r3
	movs r0, #7
	rsbs r0, r0, #0
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r0, #0x20
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0x89
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0812F458:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r7, r1, #0
	cmp r6, #0x11
	bgt _0812F488
	ldrh r0, [r4, #8]
	cmp r0, #1
	bne _0812F488
	movs r0, #0
	strh r0, [r4, #0xe]
_0812F488:
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r4, #0x85
	lsls r4, r4, #2
	adds r1, r5, r4
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0812F4A8
	asrs r0, r0, #2
	b _0812F4AE
_0812F4A8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0812F4AE:
	adds r3, r0, #0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r6, #0
	ldrsh r2, [r0, r6]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _0812F4CE
	asrs r0, r0, #2
	b _0812F4D4
_0812F4CE:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0812F4D4:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0812F4DE
	movs r3, #0xc8
	b _0812F4E8
_0812F4DE:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0812F4E8
	adds r3, r0, #0
_0812F4E8:
	cmp r2, #0xc8
	ble _0812F4F0
	movs r2, #0xc8
	b _0812F4FA
_0812F4F0:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0812F4FA
	adds r2, r0, #0
_0812F4FA:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r3
	strh r0, [r5, #0x10]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r2
	strh r0, [r5, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0812F51E
	cmp r2, #0
	bne _0812F51E
	movs r0, #1
	b _0812F520
_0812F51E:
	movs r0, #0
_0812F520:
	cmp r0, #0
	beq _0812F5D6
	ldr r1, _0812F5DC @ =0x0000046B
	adds r0, r5, r1
	movs r2, #0
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xc
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r2, [r0]
	ldr r6, _0812F5E0 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r3, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	ldr r3, _0812F5E4 @ =0x0000046C
	adds r0, r5, r3
	strb r1, [r0]
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r4, [r0]
	movs r3, #0x1a
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0812F5DC @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_08130eec
	adds r0, r5, #0
	bl FUN_080e6204
	ldr r4, _0812F5E8 @ =0x000001DF
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #2
	beq _0812F59E
	movs r0, #4
	ldr r6, _0812F5EC @ =0x00000222
	adds r2, r5, r6
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0812F59E:
	movs r0, #0x80
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r1, [r0]
	ldr r4, _0812F5F0 @ =0x0000024E
	adds r0, r5, r4
	strh r1, [r0]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r6, #0xfe
	lsls r6, r6, #1
	adds r0, r5, r6
	ldrb r0, [r0]
	strb r0, [r5, #5]
	movs r1, #0x10
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
_0812F5D6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812F5DC: .4byte 0x0000046B
_0812F5E0: .4byte 0x00000469
_0812F5E4: .4byte 0x0000046C
_0812F5E8: .4byte 0x000001DF
_0812F5EC: .4byte 0x00000222
_0812F5F0: .4byte 0x0000024E

	thumb_func_start FUN_0812f5f4
FUN_0812f5f4: @ 0x0812F5F4
	push {r4, r5, r6, lr}
	sub sp, #0x28
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0812F610 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812F614
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812F616
	.align 2, 0
_0812F610: .4byte 0x0000046D
_0812F614:
	movs r0, #0
_0812F616:
	cmp r0, #0
	beq _0812F654
	adds r0, r5, #0
	movs r1, #3
	bl FUN_080ef86c
	adds r0, r5, #0
	bl FUN_080e8360
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r0, #0x3c
	strh r0, [r1]
	ldr r2, _0812F710 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0812F714 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0812F718 @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r6, _0812F71C @ =0x00000452
	adds r0, r5, r6
	strb r1, [r0]
	ldr r0, _0812F720 @ =0x00000453
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0812F654:
	movs r2, #0x80
	lsls r2, r2, #8
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _0812F66A
	b _0812F80E
_0812F66A:
	ldr r0, [r5, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0812F67E
	b _0812F7C8
_0812F67E:
	ldr r1, _0812F724 @ =0x0000046B
	adds r0, r5, r1
	movs r4, #1
	strb r4, [r0]
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _0812F6E6
	movs r1, #8
	ldrsh r0, [r5, r1]
	str r0, [sp]
	movs r3, #0xa
	ldrsh r0, [r5, r3]
	str r0, [sp, #4]
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	str r0, [sp, #8]
	movs r3, #0xce
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	adds r3, #8
	adds r0, r5, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r5]
	str r0, [sp, #0x1c]
	ldr r1, _0812F728 @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r3, sp
	str r3, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_0812F6E6:
	ldr r1, _0812F72C @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0812F734
	ldr r0, _0812F730 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r1, r4, #0
	lsls r1, r3
	b _0812F746
	.align 2, 0
_0812F710: .4byte 0x030046B8
_0812F714: .4byte 0x000003FF
_0812F718: .4byte 0x0203B400
_0812F71C: .4byte 0x00000452
_0812F720: .4byte 0x00000453
_0812F724: .4byte 0x0000046B
_0812F728: .4byte 0xFFFF0000
_0812F72C: .4byte 0x000001DF
_0812F730: .4byte 0x030046A0
_0812F734:
	ldr r0, _0812F7B0 @ =0x030046A0
	ldr r2, [r0]
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r2, r2, r1
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0812F746:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _0812F75E
	adds r0, r5, #0
	bl FUN_080e6658
_0812F75E:
	ldr r4, _0812F7B4 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r2, _0812F7B8 @ =0x0000046D
	adds r0, r5, r2
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	ldr r6, _0812F7BC @ =0x0000046B
	adds r0, r5, r6
	strb r1, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r1, [r0]
	movs r4, #2
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #1
	adds r0, r5, r6
	strb r3, [r0]
	ldr r3, _0812F7C0 @ =0x0000046A
	adds r0, r5, r3
	strb r4, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r1, _0812F7C4 @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _0812F80E
	.align 2, 0
_0812F7B0: .4byte 0x030046A0
_0812F7B4: .4byte FUN_080e48d0
_0812F7B8: .4byte 0x0000046D
_0812F7BC: .4byte 0x0000046B
_0812F7C0: .4byte 0x0000046A
_0812F7C4: .4byte 0x0000046C
_0812F7C8:
	movs r1, #1
	ldr r2, _0812F7E0 @ =0x0000025D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812F7E4
	ldr r0, [r5, #0x44]
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0812F7EE
	b _0812F7F2
	.align 2, 0
_0812F7E0: .4byte 0x0000025D
_0812F7E4:
	ldr r0, [r5, #0x44]
	ldr r0, [r0, #0x28]
	ands r0, r1
	cmp r0, #0
	beq _0812F7F2
_0812F7EE:
	movs r0, #1
	b _0812F7F4
_0812F7F2:
	movs r0, #0
_0812F7F4:
	cmp r0, #0
	beq _0812F804
	movs r3, #0x9a
	lsls r3, r3, #2
	adds r0, r5, r3
	bl FUN_080136b4
	b _0812F80E
_0812F804:
	movs r6, #0x9a
	lsls r6, r6, #2
	adds r0, r5, r6
	bl FUN_08013698
_0812F80E:
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0812f818
FUN_0812f818: @ 0x0812F818
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08130460
	adds r0, r4, #0
	bl FUN_08130610
	adds r0, r4, #0
	bl FUN_0813069c
	adds r0, r4, #0
	bl FUN_080e8614
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0812f83c
FUN_0812f83c: @ 0x0812F83C
	bx lr
	.align 2, 0

	thumb_func_start FUN_0812f840
FUN_0812f840: @ 0x0812F840
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _0812F880 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812F854
	movs r0, #0
	strb r0, [r1]
_0812F854:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _0812F884 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812F88C
	ldr r3, _0812F888 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0812F89C
	.align 2, 0
_0812F880: .4byte 0x0000046C
_0812F884: .4byte 0x0000A02F
_0812F888: .4byte 0x00000482
_0812F88C:
	ldr r4, _0812F8C0 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0812F89C
	movs r0, #1
	strh r0, [r2]
_0812F89C:
	ldr r1, _0812F8C4 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812F8C8
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
	b _0812F8E0
	.align 2, 0
_0812F8C0: .4byte 0x00000482
_0812F8C4: .4byte 0x0000025D
_0812F8C8:
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
_0812F8E0:
	ldr r2, _0812F92C @ =0x000004A4
	adds r4, r5, r2
	ldr r0, [r4]
	bl FUN_08235fd8
	cmp r0, #0
	beq _0812F938
	ldr r1, [r4]
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812F938
	movs r2, #0xd
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _0812F930 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _0812F934 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _0812F9DE
	.align 2, 0
_0812F92C: .4byte 0x000004A4
_0812F930: .4byte 0x00000469
_0812F934: .4byte 0x0000046C
_0812F938:
	ldr r1, _0812F9B0 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	str r6, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812F9C4
	movs r1, #0xc
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0812F9B4 @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	ldr r4, _0812F9B8 @ =0x0000046A
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _0812F9BC @ =0x00000484
	adds r0, r5, r1
	str r2, [r0]
	adds r3, #3
	adds r0, r5, r3
	movs r1, #1
	strb r1, [r0]
	movs r4, #0xb7
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r3, [r0]
	ldr r4, _0812F9C0 @ =0x0000046D
	adds r0, r5, r4
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_08130eec
	adds r0, r5, #0
	bl FUN_080e6204
	b _0812F9DE
	.align 2, 0
_0812F9B0: .4byte 0x000004A4
_0812F9B4: .4byte 0x00000469
_0812F9B8: .4byte 0x0000046A
_0812F9BC: .4byte 0x00000484
_0812F9C0: .4byte 0x0000046D
_0812F9C4:
	ldr r4, _0812F9E8 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0812F9DE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812F9E8: .4byte 0x00000484

	thumb_func_start FUN_0812f9ec
FUN_0812f9ec: @ 0x0812F9EC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov sb, r0
	ldr r2, _0812FA54 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812FA10
	movs r0, #0
	strb r0, [r1]
_0812FA10:
	movs r3, #0xc1
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812FA26
	b _0812FBD2
_0812FA26:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r1, _0812FA58 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812FA60
	ldr r3, _0812FA5C @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0812FA70
	.align 2, 0
_0812FA54: .4byte 0x0000046C
_0812FA58: .4byte 0x0000A02F
_0812FA5C: .4byte 0x00000482
_0812FA60:
	ldr r1, _0812FA94 @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0812FA70
	movs r0, #1
	strh r0, [r2]
_0812FA70:
	ldr r3, _0812FA98 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0812FA9C
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
	b _0812FAB4
	.align 2, 0
_0812FA94: .4byte 0x00000482
_0812FA98: .4byte 0x0000025D
_0812FA9C:
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
_0812FAB4:
	movs r2, #0x80
	lsls r2, r2, #7
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	bne _0812FAF0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #4
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812FAE4
	movs r0, #1
	b _0812FAE6
_0812FAE4:
	movs r0, #0
_0812FAE6:
	cmp r0, #0
	bne _0812FAF0
	adds r0, r5, #0
	bl FUN_081307b0
_0812FAF0:
	ldr r3, _0812FB5C @ =0x000004A4
	adds r4, r5, r3
	ldr r0, [r4]
	bl FUN_08235fd8
	adds r6, r0, #0
	cmp r6, #0
	bne _0812FB6C
	ldr r1, [r4]
	mov r0, r8
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e5ed4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812FBA8
	movs r1, #5
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _0812FB60 @ =0x00000469
	adds r0, r5, r3
	strb r6, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r6, [r0]
	ldr r0, _0812FB64 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0812FB68 @ =0xFFFFBFFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
	b _0812FBD2
	.align 2, 0
_0812FB5C: .4byte 0x000004A4
_0812FB60: .4byte 0x00000469
_0812FB64: .4byte 0x0000046C
_0812FB68: .4byte 0xFFFFBFFF
_0812FB6C:
	ldr r1, [r4]
	mov r3, r8
	str r3, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_080e60b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812FBA8
	movs r2, #6
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0812FBE0 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _0812FBE4 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_0812FBA8:
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r7]
	ands r0, r1
	cmp r0, #0
	bne _0812FBC8
	ldr r0, _0812FBE8 @ =0x0000065C
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _0812FBC8
	movs r0, #0x80
	lsls r0, r0, #6
	orrs r1, r0
	str r1, [r7]
_0812FBC8:
	ldr r3, _0812FBE4 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0812FBD2:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812FBE0: .4byte 0x00000469
_0812FBE4: .4byte 0x00000484
_0812FBE8: .4byte 0x0000065C

	thumb_func_start FUN_0812fbec
FUN_0812fbec: @ 0x0812FBEC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0812FC04 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812FC08
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812FC0A
	.align 2, 0
_0812FC04: .4byte 0x0000046C
_0812FC08:
	movs r0, #0
_0812FC0A:
	cmp r0, #0
	beq _0812FC48
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _0812FC40 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0812FC44 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	b _0812FCCE
	.align 2, 0
_0812FC40: .4byte 0x0000046D
_0812FC44: .4byte 0x0000046B
_0812FC48:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0812FCCE
	ldr r2, _0812FCB8 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0812FCC4
	movs r1, #7
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r3, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r3, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r1, [r0]
	ldr r1, _0812FCBC @ =0x00000484
	adds r0, r5, r1
	str r3, [r0]
	adds r2, #3
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r2, [r0]
	ldr r4, _0812FCC0 @ =0x0000046D
	adds r0, r5, r4
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r3, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r3, [r0]
	b _0812FCCE
	.align 2, 0
_0812FCB8: .4byte 0x0000046B
_0812FCBC: .4byte 0x00000484
_0812FCC0: .4byte 0x0000046D
_0812FCC4:
	ldr r4, _0812FCD4 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0812FCCE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0812FCD4: .4byte 0x00000484

	thumb_func_start FUN_0812fcd8
FUN_0812fcd8: @ 0x0812FCD8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0812FCF0 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812FCF4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812FCF6
	.align 2, 0
_0812FCF0: .4byte 0x0000046C
_0812FCF4:
	movs r0, #0
_0812FCF6:
	adds r4, r0, #0
	cmp r4, #0
	beq _0812FD3C
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	movs r3, #2
	ldr r2, _0812FD30 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r6, _0812FD34 @ =0x0000046B
	adds r0, r5, r6
	strb r2, [r0]
	ldr r1, _0812FD38 @ =0x00000553
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
	b _0812FDAE
	.align 2, 0
_0812FD30: .4byte 0x0000046D
_0812FD34: .4byte 0x0000046B
_0812FD38: .4byte 0x00000553
_0812FD3C:
	ldr r2, _0812FD98 @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0812FDA4
	movs r1, #0xc
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	subs r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0812FD9C @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #3
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r3, [r0]
	movs r2, #0x1a
	ldr r6, _0812FDA0 @ =0x0000046D
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0812FD98 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	b _0812FDAE
	.align 2, 0
_0812FD98: .4byte 0x0000046B
_0812FD9C: .4byte 0x00000484
_0812FDA0: .4byte 0x0000046D
_0812FDA4:
	ldr r6, _0812FDB4 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0812FDAE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812FDB4: .4byte 0x00000484

	thumb_func_start FUN_0812fdb8
FUN_0812fdb8: @ 0x0812FDB8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0812FDE0 @ =0x0000046C
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812FDE4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0812FDE6
	.align 2, 0
_0812FDE0: .4byte 0x0000046C
_0812FDE4:
	movs r0, #0
_0812FDE6:
	cmp r0, #0
	beq _0812FE1A
	ldr r3, _0812FE44 @ =0x000005A4
	adds r0, r7, r3
	ldr r3, [r0]
	movs r1, #0
	ldr r4, _0812FE48 @ =0x0000046D
	adds r0, r7, r4
	movs r2, #1
	strb r2, [r0]
	subs r4, #2
	adds r0, r7, r4
	strb r1, [r0]
	adds r4, #0xe8
	adds r0, r7, r4
	strb r1, [r0]
	adds r4, #0x25
	adds r0, r7, r4
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
	subs r4, #0xf6
	adds r0, r7, r4
	strh r2, [r0]
_0812FE1A:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812FE30
	b _0813005C
_0812FE30:
	movs r1, #4
	movs r0, #0xcc
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0812FE4C
	movs r0, #1
	b _0812FE4E
	.align 2, 0
_0812FE44: .4byte 0x000005A4
_0812FE48: .4byte 0x0000046D
_0812FE4C:
	movs r0, #0
_0812FE4E:
	adds r4, r0, #0
	cmp r4, #0
	beq _0812FEF0
	adds r0, r7, #0
	movs r1, #0x40
	movs r2, #0x40
	bl FUN_081304a8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0812FEE8
	ldr r2, _0812FED0 @ =0x00000482
	adds r1, r7, r2
	movs r4, #0
	movs r5, #0
	movs r6, #1
	movs r0, #1
	strh r0, [r1]
	adds r0, r7, #0
	bl FUN_0813101c
	adds r0, r7, #0
	bl FUN_080e6204
	ldr r0, _0812FED4 @ =0x0000065E
	add r0, r8
	strh r5, [r0]
	movs r1, #0xf
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r7, r3
	strb r4, [r0]
	ldr r2, _0812FED8 @ =0x00000469
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _0812FEDC @ =0x00000484
	adds r0, r7, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r7, r2
	strb r6, [r0]
	ldr r2, _0812FEE0 @ =FUN_0812ef50
	movs r1, #0x21
	adds r3, #3
	adds r0, r7, r3
	strb r6, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	ldr r4, _0812FEE4 @ =0x00000553
	adds r0, r7, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	b _0813005C
	.align 2, 0
_0812FED0: .4byte 0x00000482
_0812FED4: .4byte 0x0000065E
_0812FED8: .4byte 0x00000469
_0812FEDC: .4byte 0x00000484
_0812FEE0: .4byte FUN_0812ef50
_0812FEE4: .4byte 0x00000553
_0812FEE8:
	adds r0, r7, #0
	bl FUN_08130508
	b _0813005C
_0812FEF0:
	ldr r3, _0812FF40 @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	cmp r0, #0x3c
	bgt _0812FEFC
	b _08130058
_0812FEFC:
	adds r0, r7, #0
	bl FUN_0813101c
	adds r0, r7, #0
	bl FUN_080e6204
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _0812FF58
	ldr r6, _0812FF44 @ =0x030046B8
	ldr r0, [r6]
	adds r5, r0, #1
	ldr r2, _0812FF48 @ =0x000003FF
	mov ip, r2
	ands r5, r2
	str r5, [r6]
	lsls r0, r5, #1
	ldr r3, _0812FF4C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0812FF54
	movs r1, #0xf
	adds r2, #0x69
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0812FF50 @ =0x00000469
	b _0812FF82
	.align 2, 0
_0812FF40: .4byte 0x00000484
_0812FF44: .4byte 0x030046B8
_0812FF48: .4byte 0x000003FF
_0812FF4C: .4byte 0x0203B400
_0812FF50: .4byte 0x00000469
_0812FF54:
	movs r1, #7
	b _08130000
_0812FF58:
	ldr r6, _0812FFE4 @ =0x030046B8
	ldr r0, [r6]
	adds r5, r0, #1
	ldr r3, _0812FFE8 @ =0x000003FF
	mov ip, r3
	ands r5, r3
	str r5, [r6]
	lsls r0, r5, #1
	ldr r1, _0812FFEC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08130000
	movs r1, #0xf
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r4, [r0]
	adds r3, #0x6a
_0812FF82:
	adds r0, r7, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r7, r3
	str r4, [r0]
	ldr r1, _0812FFF0 @ =0x0000046C
	adds r0, r7, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _0812FFF4 @ =FUN_0812ef50
	mov sb, r2
	movs r2, #0x21
	subs r3, #0x17
	adds r0, r7, r3
	strb r1, [r0]
	ldr r1, _0812FFF8 @ =0x0000046B
	adds r0, r7, r1
	strb r4, [r0]
	adds r3, #0xe6
	adds r0, r7, r3
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, sb
	str r2, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r4, [r0]
	adds r0, r5, #1
	mov r4, ip
	ands r0, r4
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _0812FFEC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x3c
	ldr r1, _0812FFFC @ =0x0000065E
	add r1, r8
	strh r0, [r1]
	b _0813005C
	.align 2, 0
_0812FFE4: .4byte 0x030046B8
_0812FFE8: .4byte 0x000003FF
_0812FFEC: .4byte 0x0203B400
_0812FFF0: .4byte 0x0000046C
_0812FFF4: .4byte FUN_0812ef50
_0812FFF8: .4byte 0x0000046B
_0812FFFC: .4byte 0x0000065E
_08130000:
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _08130050 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r7, r3
	str r4, [r0]
	ldr r1, _08130054 @ =0x0000046C
	adds r0, r7, r1
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r2, [r0]
	subs r3, #0x17
	adds r0, r7, r3
	strb r1, [r0]
	subs r3, #2
	adds r0, r7, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	b _0813005C
	.align 2, 0
_08130050: .4byte 0x00000469
_08130054: .4byte 0x0000046C
_08130058:
	adds r0, #1
	str r0, [r1]
_0813005C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08130068
FUN_08130068: @ 0x08130068
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081300A0 @ =0x0000046C
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813007A
	movs r0, #0
	strb r0, [r1]
_0813007A:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08130098
	ldr r0, _081300A4 @ =0x00000484
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08130098:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081300A0: .4byte 0x0000046C
_081300A4: .4byte 0x00000484

	thumb_func_start FUN_081300a8
FUN_081300a8: @ 0x081300A8
	push {lr}
	adds r1, r0, #0
	ldr r0, _081300C8 @ =0x0000046C
	adds r2, r1, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081300BA
	movs r0, #0
	strb r0, [r2]
_081300BA:
	ldr r0, _081300CC @ =0x00000484
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_081300C8: .4byte 0x0000046C
_081300CC: .4byte 0x00000484

	thumb_func_start FUN_081300d0
FUN_081300d0: @ 0x081300D0
	ldr r1, _081300E4 @ =0x00000634
	adds r2, r0, r1
	ldr r1, _081300E8 @ =0x085AD6BC
	str r1, [r2]
	ldr r1, _081300EC @ =0x00000644
	adds r0, r0, r1
	ldr r1, _081300F0 @ =0x085AD700
	str r1, [r0]
	bx lr
	.align 2, 0
_081300E4: .4byte 0x00000634
_081300E8: .4byte 0x085AD6BC
_081300EC: .4byte 0x00000644
_081300F0: .4byte 0x085AD700

	thumb_func_start FUN_081300f4
FUN_081300f4: @ 0x081300F4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x28
	adds r6, r0, #0
	ldr r4, _0813017C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r1, #0x80
	orrs r0, r1
	ldr r2, _08130180 @ =0x0000FFFF
	mov r8, r2
	ands r0, r2
	movs r5, #0x80
	lsls r5, r5, #0x10
	orrs r0, r5
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0xc]
	str r5, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _08130184 @ =FUN_0812dd24
	str r6, [sp]
	ldr r0, _08130188 @ =0x0000510B
	str r0, [sp, #4]
	adds r0, r6, #0
	add r1, sp, #8
	bl FUN_080e38a8
	ldr r0, [sp, #0x18]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r1, #4]
	str r5, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _0813018C @ =FUN_0812dce4
	movs r0, #0
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r6, #0
	bl FUN_080e3984
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813017C: .4byte 0xFFFF0000
_08130180: .4byte 0x0000FFFF
_08130184: .4byte FUN_0812dd24
_08130188: .4byte 0x0000510B
_0813018C: .4byte FUN_0812dce4

	thumb_func_start FUN_08130190
FUN_08130190: @ 0x08130190
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _081301F4 @ =0x0000065C
	adds r0, r1, r2
	movs r2, #0
	strh r2, [r0]
	ldr r3, _081301F8 @ =0x0000065E
	adds r0, r1, r3
	strh r2, [r0]
	movs r0, #0xcc
	lsls r0, r0, #3
	adds r1, r1, r0
	strh r2, [r1]
	adds r0, r4, #0
	bl FUN_080e6204
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
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
	beq _081301FC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08130204
	.align 2, 0
_081301F4: .4byte 0x0000065C
_081301F8: .4byte 0x0000065E
_081301FC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08130204:
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
	beq _08130228
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08130230
_08130228:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08130230:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08130268 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081302A0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0813026C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08130260
	ldrb r0, [r4, #5]
_08130260:
	subs r0, #1
	strh r0, [r4, #8]
	b _0813027C
	.align 2, 0
_08130268: .4byte 0x0000FFFF
_0813026C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0813027C
	strh r1, [r4, #8]
_0813027C:
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
	bne _081302A0
	movs r0, #1
	strb r0, [r4, #7]
_081302A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081302a8
FUN_081302a8: @ 0x081302A8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xe
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081302f8
FUN_081302f8: @ 0x081302F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	beq _08130310
	b _08130442
_08130310:
	ldr r0, _081303CC @ =0x03002BE0
	mov sb, r0
	ldr r2, [r0]
	cmp r2, #0
	bne _0813031C
	b _08130442
_0813031C:
	ldr r1, _081303D0 @ =0x000004A4
	adds r1, r1, r5
	mov r8, r1
	ldr r0, [r1]
	adds r7, r5, #0
	adds r7, #8
	adds r2, #0x2c
	adds r1, r7, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08130336
	b _08130442
_08130336:
	movs r2, #0x95
	lsls r2, r2, #3
	adds r3, r5, r2
	ldr r2, [r3]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r3]
	movs r2, #0
	strh r6, [r0, #6]
	movs r3, #0xec
	lsls r3, r3, #1
	adds r4, r5, r3
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0x24
	str r0, [r4]
	movs r1, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _081303D4 @ =0x00000484
	adds r0, r5, r1
	str r6, [r0]
	adds r3, #2
	adds r0, r5, r3
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r0, [r0]
	mov sb, r0
	ldr r3, _081303D8 @ =0x0000046D
	adds r0, r5, r3
	strb r1, [r0]
	subs r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081303DC @ =0x00000553
	adds r0, r5, r2
	strb r1, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	mov r1, sb
	str r1, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r6, [r0]
	mov r3, r8
	ldr r6, [r3]
	ldr r0, [r4]
	adds r4, r0, #0
	adds r4, #8
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _081303E0
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r5, r1
	b _08130404
	.align 2, 0
_081303CC: .4byte 0x03002BE0
_081303D0: .4byte 0x000004A4
_081303D4: .4byte 0x00000484
_081303D8: .4byte 0x0000046D
_081303DC: .4byte 0x00000553
_081303E0:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _081303FE
	cmp r0, #2
	beq _0813040C
	adds r0, r5, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
	b _0813040C
_081303FE:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
_08130404:
	ldr r1, _08130450 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
_0813040C:
	ldr r2, _08130454 @ =0x00004010
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08130458 @ =0x00000482
	adds r1, r5, r0
	movs r4, #0
	movs r0, #3
	strh r0, [r1]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r3, r5, r1
	ldr r1, [r3]
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r0, #2
	orrs r0, r2
	strh r0, [r1]
	ldr r0, [r3]
	ldr r3, _0813045C @ =0x0000065C
	adds r0, r0, r3
	strh r4, [r0]
_08130442:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08130450: .4byte 0xFFFFFDFF
_08130454: .4byte 0x00004010
_08130458: .4byte 0x00000482
_0813045C: .4byte 0x0000065C

	thumb_func_start FUN_08130460
FUN_08130460: @ 0x08130460
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08130498
	ldr r0, _081304A0 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _081304A4 @ =0x000003FF
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08130498
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0xcc
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r2, [r1]
	ands r0, r2
	strh r0, [r1]
_08130498:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081304A0: .4byte 0x03002BE0
_081304A4: .4byte 0x000003FF

	thumb_func_start FUN_081304a8
FUN_081304a8: @ 0x081304A8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	bl FUN_080865c0
	adds r3, r0, #0
	cmp r3, #0
	beq _081304FE
	mov r4, sp
	adds r2, r5, #0
	adds r2, #8
	ldrh r0, [r3]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _081304E8
	rsbs r0, r0, #0
_081304E8:
	cmp r0, r6
	bgt _081304FE
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _081304F6
	rsbs r0, r0, #0
_081304F6:
	cmp r0, r7
	bgt _081304FE
	movs r0, #1
	b _08130500
_081304FE:
	movs r0, #0
_08130500:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08130508
FUN_08130508: @ 0x08130508
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08130604
	bl FUN_080865c0
	adds r4, r0, #0
	cmp r4, #0
	beq _08130604
	ldr r2, _08130550 @ =0x000004A4
	adds r0, r6, r2
	ldr r5, [r0]
	adds r7, r6, #0
	adds r7, #8
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08130554
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r0, r6, r3
	b _0813057A
	.align 2, 0
_08130550: .4byte 0x000004A4
_08130554:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08130574
	cmp r0, #2
	beq _08130570
	adds r0, r6, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08130570:
	movs r0, #1
	b _08130584
_08130574:
	movs r7, #0xc0
	lsls r7, r7, #1
	adds r0, r6, r7
_0813057A:
	ldr r1, _081305F4 @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08130584:
	cmp r0, #0
	beq _08130604
	movs r5, #4
	movs r1, #0xcc
	lsls r1, r1, #3
	add r1, r8
	ldrh r2, [r1]
	movs r0, #4
	movs r3, #0
	movs r4, #0
	orrs r0, r2
	strh r0, [r1]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r2, [r0]
	movs r1, #1
	ldr r7, _081305F8 @ =0x0000046D
	adds r0, r6, r7
	strb r1, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r1, [r0]
	adds r7, #0x25
	adds r0, r6, r7
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	movs r2, #7
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r3, [r0]
	adds r7, #1
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _081305FC @ =0x0000046A
	adds r0, r6, r3
	strb r2, [r0]
	adds r7, #0x1b
	adds r0, r6, r7
	str r4, [r0]
	ldr r2, _08130600 @ =0x0000046C
	adds r0, r6, r2
	strb r1, [r0]
	adds r3, #0x18
	adds r0, r6, r3
	strh r5, [r0]
	movs r0, #1
	b _08130606
	.align 2, 0
_081305F4: .4byte 0xFFFFFDFF
_081305F8: .4byte 0x0000046D
_081305FC: .4byte 0x0000046A
_08130600: .4byte 0x0000046C
_08130604:
	movs r0, #0
_08130606:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08130610
FUN_08130610: @ 0x08130610
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #1
	beq _08130696
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r4, [r0]
	bl FUN_08086878
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _0813063C
	bl FUN_08086850
	cmp r0, #0
	bne _0813065C
_0813063C:
	ldr r0, _08130658 @ =0x00000662
	adds r1, r4, r0
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r2, r4, r1
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _08130696
	.align 2, 0
_08130658: .4byte 0x00000662
_0813065C:
	ldr r2, _0813066C @ =0x00000662
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08130670
	subs r0, #1
	strh r0, [r1]
	b _08130696
	.align 2, 0
_0813066C: .4byte 0x00000662
_08130670:
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	movs r1, #4
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813068A
	movs r0, #1
	b _0813068C
_0813068A:
	movs r0, #0
_0813068C:
	cmp r0, #0
	bne _08130696
	adds r0, r5, #0
	bl FUN_08130508
_08130696:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0813069c
FUN_0813069c: @ 0x0813069C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081307A6
	movs r2, #0x10
	movs r3, #0xcc
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081306CA
	movs r0, #1
	b _081306CC
_081306CA:
	movs r0, #0
_081306CC:
	cmp r0, #0
	beq _081307A6
	movs r1, #0x20
	ldr r0, _081306E8 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _081306EC @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081306F0
	movs r0, #1
	b _081306F2
	.align 2, 0
_081306E8: .4byte 0x030046A0
_081306EC: .4byte 0x00000934
_081306F0:
	movs r0, #0
_081306F2:
	cmp r0, #0
	beq _08130780
	movs r1, #8
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08130704
	movs r0, #1
	b _08130706
_08130704:
	movs r0, #0
_08130706:
	adds r5, r0, #0
	cmp r5, #0
	bne _08130768
	adds r0, r4, #0
	bl FUN_080e6204
	movs r1, #7
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r5, [r0]
	ldr r2, _08130770 @ =0x00000469
	adds r0, r4, r2
	strb r5, [r0]
	adds r3, #2
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08130774 @ =0x00000484
	adds r0, r4, r1
	str r5, [r0]
	adds r2, #3
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r4, r3
	ldr r2, [r0]
	ldr r3, _08130778 @ =0x0000046D
	adds r0, r4, r3
	strb r1, [r0]
	subs r3, #2
	adds r0, r4, r3
	strb r5, [r0]
	adds r3, #0xe8
	adds r0, r4, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	strh r5, [r0]
	ldrh r1, [r6]
	movs r0, #8
	orrs r0, r1
	strh r0, [r6]
_08130768:
	ldr r3, _0813077C @ =0x00000482
	adds r1, r4, r3
	movs r0, #5
	b _081307A4
	.align 2, 0
_08130770: .4byte 0x00000469
_08130774: .4byte 0x00000484
_08130778: .4byte 0x0000046D
_0813077C: .4byte 0x00000482
_08130780:
	movs r1, #8
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _0813078E
	movs r0, #1
	b _08130790
_0813078E:
	movs r0, #0
_08130790:
	cmp r0, #0
	beq _081307A6
	movs r0, #9
	rsbs r0, r0, #0
	ldrh r1, [r6]
	ands r0, r1
	strh r0, [r6]
	ldr r0, _081307AC @ =0x00000482
	adds r1, r4, r0
	movs r0, #1
_081307A4:
	strh r0, [r1]
_081307A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081307AC: .4byte 0x00000482

	thumb_func_start FUN_081307b0
FUN_081307b0: @ 0x081307B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	str r4, [sp, #8]
	ldr r2, _08130898 @ =0x0203B400
	mov sl, r2
	ldr r7, _0813089C @ =0x030046B8
	ldr r0, [r7]
	adds r0, #1
	ldr r6, _081308A0 @ =0x000003FF
	ands r0, r6
	lsls r1, r0, #1
	add r1, sl
	ldrh r1, [r1]
	ands r1, r6
	movs r2, #0x80
	lsls r2, r2, #1
	adds r2, r2, r1
	mov sb, r2
	adds r0, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	subs r0, #0x3f
	ldrb r1, [r4, #5]
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, _081308A4 @ =0x00000484
	adds r0, r4, r2
	ldr r0, [r0]
	movs r1, #0x1e
	bl Mod
	cmp r0, #0
	beq _08130814
	b _081309C4
_08130814:
	ldr r0, _081308A8 @ =0x0000065C
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _08130822
	b _081309D0
_08130822:
	ldr r2, _081308AC @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r0, r0, #0xe
	ldrh r1, [r4, #8]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r3, _081308B0 @ =0xFFFF0000
	ldrh r1, [r4, #0xa]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r0, r0, #0xe
	ldrh r2, [r4, #0xc]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
	ldr r1, _081308B4 @ =0x000004A4
	adds r0, r4, r1
	ldr r0, [r0]
	adds r1, r4, #0
	adds r1, #8
	mov r2, sp
	bl FUN_0823599c
	cmp r0, #0
	bne _081308DC
	movs r1, #0x10
	movs r0, #0xcc
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081308B8
	movs r0, #1
	b _081308BA
	.align 2, 0
_08130898: .4byte 0x0203B400
_0813089C: .4byte 0x030046B8
_081308A0: .4byte 0x000003FF
_081308A4: .4byte 0x00000484
_081308A8: .4byte 0x0000065C
_081308AC: .4byte 0x085B0A08
_081308B0: .4byte 0xFFFF0000
_081308B4: .4byte 0x000004A4
_081308B8:
	movs r0, #0
_081308BA:
	cmp r0, #0
	bne _081308C6
	ldr r2, _081308D4 @ =0x00000482
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
_081308C6:
	adds r0, r4, #0
	bl FUN_080e6204
	ldr r1, _081308D8 @ =0x0000065C
	add r1, r8
	movs r0, #0
	b _081309D8
	.align 2, 0
_081308D4: .4byte 0x00000482
_081308D8: .4byte 0x0000065C
_081308DC:
	movs r0, #0x83
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r7]
	adds r0, #1
	ands r0, r6
	str r0, [r7]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0813090C
	ldr r2, _08130908 @ =0x00000482
	adds r1, r4, r2
	movs r0, #4
	b _08130912
	.align 2, 0
_08130908: .4byte 0x00000482
_0813090C:
	ldr r0, _0813093C @ =0x00000482
	adds r1, r4, r0
	movs r0, #1
_08130912:
	strh r0, [r1]
	ldr r1, _08130940 @ =0x000004A4
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r7, [sp, #8]
	adds r7, #8
	movs r2, #0x83
	lsls r2, r2, #2
	adds r5, r4, r2
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_0823599c
	cmp r0, #0
	bne _08130944
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	b _0813096A
	.align 2, 0
_0813093C: .4byte 0x00000482
_08130940: .4byte 0x000004A4
_08130944:
	adds r0, r6, #0
	adds r1, r7, #0
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _08130964
	cmp r0, #2
	beq _08130960
	adds r0, r4, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_08130960:
	movs r0, #1
	b _08130974
_08130964:
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
_0813096A:
	ldr r1, _0813099C @ =0xFFFFFDFF
	ldrh r2, [r0]
	ands r1, r2
	strh r1, [r0]
	movs r0, #0
_08130974:
	adds r5, r0, #0
	cmp r5, #0
	bne _08130986
	adds r0, r4, #0
	bl FUN_080e6204
	ldr r0, _081309A0 @ =0x0000065C
	add r0, r8
	strh r5, [r0]
_08130986:
	movs r1, #8
	movs r0, #0xcc
	lsls r0, r0, #3
	add r0, r8
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081309A4
	movs r0, #1
	b _081309A6
	.align 2, 0
_0813099C: .4byte 0xFFFFFDFF
_081309A0: .4byte 0x0000065C
_081309A4:
	movs r0, #0
_081309A6:
	cmp r0, #0
	beq _081309B8
	movs r1, #0x3c
	ldr r0, _081309B4 @ =0x0000065C
	add r0, r8
	strh r1, [r0]
	b _081309DA
	.align 2, 0
_081309B4: .4byte 0x0000065C
_081309B8:
	ldr r1, _081309C0 @ =0x0000065C
	add r1, r8
	movs r0, #0x78
	b _081309D8
	.align 2, 0
_081309C0: .4byte 0x0000065C
_081309C4:
	ldr r0, _081309EC @ =0x0000065C
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _081309DA
_081309D0:
	ldr r1, _081309EC @ =0x0000065C
	add r1, r8
	ldrh r0, [r1]
	subs r0, #1
_081309D8:
	strh r0, [r1]
_081309DA:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081309EC: .4byte 0x0000065C

	thumb_func_start FUN_081309f0
FUN_081309f0: @ 0x081309F0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	ble _08130ABC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl FUN_080f8d60
	movs r2, #0xec
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	movs r2, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _08130AA4 @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r2, _08130AA8 @ =0x0000046C
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #0x1a
	subs r6, #0x17
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08130AAC @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_08130eec
	adds r0, r5, #0
	bl FUN_080e6204
	ldr r6, _08130AB0 @ =0x000001DF
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #2
	beq _08130A84
	movs r0, #4
	ldr r1, _08130AB4 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08130A84:
	movs r0, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0x93
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrh r1, [r0]
	ldr r2, _08130AB8 @ =0x0000024E
	adds r0, r5, r2
	strh r1, [r0]
	movs r0, #1
	b _08130ABE
	.align 2, 0
_08130AA4: .4byte 0x00000469
_08130AA8: .4byte 0x0000046C
_08130AAC: .4byte 0x0000046B
_08130AB0: .4byte 0x000001DF
_08130AB4: .4byte 0x00000222
_08130AB8: .4byte 0x0000024E
_08130ABC:
	movs r0, #0
_08130ABE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08130ac4
FUN_08130ac4: @ 0x08130AC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	mov sl, r5
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #2
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08130AF0
	movs r0, #1
	b _08130AF2
_08130AF0:
	movs r0, #0
_08130AF2:
	cmp r0, #0
	bne _08130B1C
	adds r0, r5, #0
	bl FUN_081309f0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08130B04
	b _08130D10
_08130B04:
	ldr r0, _08130B18 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08130B2A
_08130B14:
	movs r0, #0
	b _08130D12
	.align 2, 0
_08130B18: .4byte 0x03002BE0
_08130B1C:
	adds r0, r5, #0
	bl FUN_081309f0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08130B2A
	b _08130D10
_08130B2A:
	ldr r0, _08130BC8 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _08130B14
	mov r8, r0
	mov r6, sp
	adds r7, r5, #0
	adds r7, #8
	mov r4, r8
	adds r4, #0x2c
	mov r3, r8
	ldrh r0, [r3, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	movs r1, #2
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bge _08130B64
	rsbs r0, r0, #0
_08130B64:
	cmp r0, #0xff
	bgt _08130B14
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	movs r2, #4
	ldrsh r1, [r6, r2]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r3, r3, r2
	mov sb, r3
	bl FUN_0823785c
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r0, [r0]
	lsls r0, r0, #1
	cmp sb, r0
	bhs _08130B14
	mov r1, r8
	ldrh r0, [r1, #0x2c]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	ldrb r4, [r5, #5]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r3, #4
	ldrsh r1, [r6, r3]
	bl FUN_0823785c
	subs r1, r0, r4
	cmp r1, #0x80
	ble _08130BD0
	ldr r6, _08130BCC @ =0xFFFFFF00
	adds r1, r1, r6
	b _08130BDE
	.align 2, 0
_08130BC8: .4byte 0x03002BE0
_08130BCC: .4byte 0xFFFFFF00
_08130BD0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08130BDE
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_08130BDE:
	adds r0, r1, #0
	cmp r0, #0
	bge _08130BE6
	rsbs r0, r0, #0
_08130BE6:
	cmp r0, #0x20
	bgt _08130B14
	mov r0, sl
	adds r0, #8
	mov r1, r8
	adds r1, #0x2c
	movs r3, #0x80
	lsls r3, r3, #1
	movs r2, #5
	bl FUN_082340c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08130B14
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	mov r1, r8
	adds r1, #0x24
	str r1, [r0]
	ldr r0, _08130CA8 @ =0x00003FFF
	cmp sb, r0
	bgt _08130CC4
	movs r2, #0xc
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r6, _08130CAC @ =0x00000469
	adds r0, r5, r6
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r1, [r0]
	ldr r2, _08130CB0 @ =0x0000046C
	adds r0, r5, r2
	movs r2, #1
	strb r2, [r0]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r4, [r0]
	movs r3, #0x1a
	subs r6, #0x17
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08130CB4 @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_08130eec
	adds r0, r5, #0
	bl FUN_080e6204
	ldr r6, _08130CB8 @ =0x000001DF
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #2
	beq _08130C88
	movs r0, #4
	ldr r1, _08130CBC @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08130C88:
	movs r0, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r6, #0x93
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrh r1, [r0]
	ldr r2, _08130CC0 @ =0x0000024E
	adds r0, r5, r2
	strh r1, [r0]
	b _08130D10
	.align 2, 0
_08130CA8: .4byte 0x00003FFF
_08130CAC: .4byte 0x00000469
_08130CB0: .4byte 0x0000046C
_08130CB4: .4byte 0x0000046B
_08130CB8: .4byte 0x000001DF
_08130CBC: .4byte 0x00000222
_08130CC0: .4byte 0x0000024E
_08130CC4:
	movs r1, #0x10
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r2, #0
	strb r2, [r0]
	ldr r6, _08130D24 @ =0x00000469
	adds r0, r5, r6
	strb r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #0x1b
	adds r0, r5, r6
	str r2, [r0]
	ldr r1, _08130D28 @ =0x0000046C
	adds r0, r5, r1
	movs r1, #1
	strb r1, [r0]
	ldr r4, _08130D2C @ =FUN_0812f1bc
	movs r3, #3
	subs r6, #0x17
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08130D30 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_08130D10:
	movs r0, #1
_08130D12:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08130D24: .4byte 0x00000469
_08130D28: .4byte 0x0000046C
_08130D2C: .4byte FUN_0812f1bc
_08130D30: .4byte 0x0000046B

	thumb_func_start FUN_08130d34
FUN_08130d34: @ 0x08130D34
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r5
	movs r1, #4
	movs r2, #0xcc
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08130D5C
	movs r0, #1
	b _08130D5E
_08130D5C:
	movs r0, #0
_08130D5E:
	cmp r0, #0
	bne _08130E24
	adds r0, r5, #0
	bl FUN_081309f0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08130D70
	b _08130EC2
_08130D70:
	ldr r0, _08130DE8 @ =0x03002BE0
	ldr r6, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r6, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08130E24
	movs r2, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	bne _08130E24
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _08130E24
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	adds r3, r6, #0
	adds r3, #0x2c
	ldrh r0, [r6, #0x2c]
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
	ldrb r4, [r5, #5]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r6, #4
	ldrsh r1, [r2, r6]
	bl FUN_0823785c
	subs r1, r0, r4
	cmp r1, #0x80
	ble _08130DF0
	ldr r0, _08130DEC @ =0xFFFFFF00
	adds r1, r1, r0
	b _08130DFE
	.align 2, 0
_08130DE8: .4byte 0x03002BE0
_08130DEC: .4byte 0xFFFFFF00
_08130DF0:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08130DFE
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08130DFE:
	adds r0, r1, #0
	cmp r0, #0
	bge _08130E06
	rsbs r0, r0, #0
_08130E06:
	cmp r0, #0x20
	bgt _08130E24
	mov r0, r8
	adds r0, #8
	ldr r4, _08130E28 @ =0x03002BE0
	ldr r1, [r4]
	adds r1, #0x2c
	movs r3, #0x80
	lsls r3, r3, #1
	movs r2, #5
	bl FUN_082340c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08130E2C
_08130E24:
	movs r0, #0
	b _08130EC4
	.align 2, 0
_08130E28: .4byte 0x03002BE0
_08130E2C:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r4]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0xc
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08130ED0 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08130ED4 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r0, r5, r3
	movs r2, #1
	strb r2, [r0]
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r5, r6
	ldr r4, [r0]
	movs r3, #0x1a
	ldr r6, _08130ED8 @ =0x0000046D
	adds r0, r5, r6
	strb r2, [r0]
	ldr r2, _08130EDC @ =0x0000046B
	adds r0, r5, r2
	strb r1, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r3, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r5, r2
	str r4, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_08130eec
	adds r0, r5, #0
	bl FUN_080e6204
	ldr r6, _08130EE0 @ =0x000001DF
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #2
	beq _08130EAC
	movs r0, #4
	ldr r1, _08130EE4 @ =0x00000222
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_08130EAC:
	movs r0, #0x80
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _08130EE8 @ =0x0000024E
	adds r0, r5, r3
	strh r1, [r0]
_08130EC2:
	movs r0, #1
_08130EC4:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08130ED0: .4byte 0x00000469
_08130ED4: .4byte 0x00000484
_08130ED8: .4byte 0x0000046D
_08130EDC: .4byte 0x0000046B
_08130EE0: .4byte 0x000001DF
_08130EE4: .4byte 0x00000222
_08130EE8: .4byte 0x0000024E

	thumb_func_start FUN_08130eec
FUN_08130eec: @ 0x08130EEC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r0, #0x9c
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0
	mov sb, r1
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #8
	ldrsh r0, [r2, r3]
	movs r7, #8
	ldrsh r1, [r5, r7]
	subs r0, r0, r1
	movs r3, #0xc
	ldrsh r1, [r2, r3]
	movs r7, #0xc
	ldrsh r2, [r5, r7]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, _08130FDC @ =0x085B0A08
	adds r1, r0, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r2, r1, #2
	adds r2, r2, r1
	lsls r2, r2, #5
	lsrs r2, r2, #0x10
	ldr r7, _08130FE0 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r7
	orrs r1, r2
	str r1, [sp]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r7
	orrs r1, r0
	str r1, [sp, #4]
	mov r1, r8
	ldr r0, [r1, #4]
	bl FUN_08234f6c
	adds r4, r0, #0
	movs r6, #0
	mov r2, r8
	ldr r0, [r2, #4]
	ldrb r0, [r0]
	cmp sb, r0
	bge _08130FF2
	mov ip, r7
	add r3, sp, #8
	mov sl, sp
_08130F80:
	ldrh r1, [r4]
	ldrh r0, [r5, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #8]
	mov r7, ip
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r1, [r4, #2]
	ldrh r0, [r5, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r3, #4]
	ands r0, r7
	orrs r0, r1
	str r0, [r3, #4]
	mov r0, sl
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r1, r0, r1
	mov r0, sl
	movs r7, #4
	ldrsh r2, [r0, r7]
	movs r7, #4
	ldrsh r0, [r3, r7]
	muls r0, r2, r0
	adds r1, r1, r0
	cmp r1, #0
	bge _08130FE4
	ldr r1, [r4]
	adds r0, r5, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r1, r0
	beq _08130FE6
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	b _08131000
	.align 2, 0
_08130FDC: .4byte 0x085B0A08
_08130FE0: .4byte 0xFFFF0000
_08130FE4:
	adds r4, #8
_08130FE6:
	adds r6, #1
	mov r1, r8
	ldr r0, [r1, #4]
	ldrb r0, [r0]
	cmp r6, r0
	blt _08130F80
_08130FF2:
	movs r0, #0
	cmp r0, #0
	bne _08131000
	adds r0, r5, #0
	bl FUN_0813101c
	b _0813100C
_08131000:
	movs r0, #0
	mov r3, sb
	mov r2, r8
	strb r3, [r2, #2]
	strb r0, [r2, #3]
	str r4, [r2, #8]
_0813100C:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0813101c
FUN_0813101c: @ 0x0813101C
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x9c
	ldr r2, _08131070 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08131074 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08131078 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r0, [r4, #2]
	cmp r1, r0
	bne _08131056
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_08131056:
	movs r0, #0
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	ldr r0, [r4, #4]
	bl FUN_08234f6c
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08131070: .4byte 0x030046B8
_08131074: .4byte 0x000003FF
_08131078: .4byte 0x0203B400

	thumb_func_start FUN_0813107c
FUN_0813107c: @ 0x0813107C
	push {lr}
	adds r1, r0, #0
	ldr r0, [r1, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	beq _08131090
	movs r0, #0
	b _081310AE
_08131090:
	movs r2, #0x80
	lsls r2, r2, #9
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r2, _081310B4 @ =0x085AD70C
	ldrh r1, [r3, #8]
	movs r0, #1
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
_081310AE:
	pop {r1}
	bx r1
	.align 2, 0
_081310B4: .4byte 0x085AD70C

	thumb_func_start FUN_081310b8
FUN_081310b8: @ 0x081310B8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_0812f818
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _081310E8 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081310E8: .4byte 0x0000062C

	thumb_func_start FUN_081310ec
FUN_081310ec: @ 0x081310EC
	push {lr}
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_081310f8
FUN_081310f8: @ 0x081310F8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08131110 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08131114
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _0813111C
	.align 2, 0
_08131110: .4byte 0x0000025D
_08131114:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_0813111C:
	ldr r0, [r4, #0x44]
	bl Free
	ldr r1, _08131158 @ =0x0000044C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08131136
	movs r1, #0xaa
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013c70
_08131136:
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_080ec6fc
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08131158: .4byte 0x0000044C

	thumb_func_start EnemySpider_Init
EnemySpider_Init: @ 0x0813115C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1bc
	adds r7, r0, #0
	str r7, [sp, #0x30]
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	mov r8, r2
	mov r3, r8
	strh r3, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	bl FUN_080e37e8
	ldr r4, _081311EC @ =0x000001DF
	adds r0, r7, r4
	movs r5, #2
	mov sb, r5
	mov r6, sb
	strb r6, [r0]
	adds r0, r7, #0
	bl FUN_081302a8
	ldr r1, _081311F0 @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081311FC
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _081311F4 @ =0x0000528F
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _081311F8 @ =0x0000B6EE
	bl FUN_080e3804
	ldr r2, _081311EC @ =0x000001DF
	adds r0, r7, r2
	ldrb r1, [r0]
	str r0, [sp, #0xb8]
	cmp r1, #0x11
	beq _081311DC
	cmp r1, #0x17
	bne _081311E0
_081311DC:
	movs r0, #1
	strb r0, [r5, #7]
_081311E0:
	movs r3, #0xef
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0
	strb r0, [r1]
	b _08131266
	.align 2, 0
_081311EC: .4byte 0x000001DF
_081311F0: .4byte 0x0000025D
_081311F4: .4byte 0x0000528F
_081311F8: .4byte 0x0000B6EE
_081311FC:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r5, sp, #0x20
	mov sl, r5
	mov r6, r8
	str r6, [sp, #0x1c]
	add r0, sp, #0x1c
	mov r1, sl
	ldr r2, _081312E4 @ =0x05000002
	bl CpuSet
	ldr r0, _081312E8 @ =0x0000CB05
	ldr r1, _081312EC @ =0x0000528F
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
	mov r6, sb
	str r6, [sp]
	str r6, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r1, sl
	str r1, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r2, _081312F0 @ =0x000004B7
	adds r1, r7, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r3, _081312F4 @ =0x000001DF
	adds r3, r7, r3
	str r3, [sp, #0xb8]
_08131266:
	str r7, [sp, #0x38]
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r4, r4, r7
	mov sb, r4
	movs r4, #0
	mov r5, sb
	str r4, [r5]
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r6, r6, r7
	mov r8, r6
	str r4, [r6]
	ldr r1, _081312F8 @ =0x0000046F
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r3, #0
	mov sl, r3
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, _081312FC @ =0x00000474
	adds r6, r7, r5
	strh r0, [r6]
	add r5, sp, #0x28
	str r4, [sp, #0x1c]
	add r0, sp, #0x1c
	adds r1, r5, #0
	ldr r2, _081312E4 @ =0x05000002
	bl CpuSet
	ldr r0, _08131300 @ =0x000004B6
	adds r2, r7, r0
	mov r1, sl
	strb r1, [r2]
	movs r0, #0x72
	str r2, [sp, #0x1b8]
	bl prepare_08231510
	mov r3, sb
	str r3, [sp, #0x84]
	mov r4, r8
	str r4, [sp, #0x8c]
	str r6, [sp, #0x68]
	ldr r2, [sp, #0x1b8]
	adds r6, r2, #0
	cmp r0, #0
	bne _081312D4
	b _08131434
_081312D4:
	bl VM_GetPC
	cmp r0, #0
	beq _08131304
	bl Script_GetValue
	adds r1, r0, #0
	b _08131306
	.align 2, 0
_081312E4: .4byte 0x05000002
_081312E8: .4byte 0x0000CB05
_081312EC: .4byte 0x0000528F
_081312F0: .4byte 0x000004B7
_081312F4: .4byte 0x000001DF
_081312F8: .4byte 0x0000046F
_081312FC: .4byte 0x00000474
_08131300: .4byte 0x000004B6
_08131304:
	movs r1, #0
_08131306:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0813132C @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x10c]
	str r4, [sp, #0x110]
	cmp r0, #0
	beq _08131330
	bl Script_GetValue
	adds r1, r0, #0
	b _08131332
	.align 2, 0
_0813132C: .4byte 0x00000251
_08131330:
	movs r1, #0
_08131332:
	ldr r2, _08131368 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0813136C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x10c]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x114]
	cmp r0, #0
	beq _08131370
	bl Script_GetValue
	b _08131374
	.align 2, 0
_08131368: .4byte 0x00000252
_0813136C: .4byte 0x000004B4
_08131370:
	ldr r4, [sp, #0x10c]
	ldrb r0, [r4]
_08131374:
	strb r0, [r6]
	ldr r5, [sp, #0x10c]
	ldrb r1, [r5]
	ldr r6, [sp, #0x114]
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
	blt _081313AC
	cmp r1, #0
	blt _081313AC
	ldr r0, _081313B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081313AC
	ldr r0, _081313B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081313B8
_081313AC:
	movs r1, #0
	b _081313C6
	.align 2, 0
_081313B0: .4byte 0x030046A8
_081313B4: .4byte 0x030046AC
_081313B8:
	ldr r0, _081313E0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081313C6:
	ldr r2, _081313E4 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x28
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081313E8
	adds r0, #4
	b _081313F4
	.align 2, 0
_081313E0: .4byte 0x030046A4
_081313E4: .4byte 0x00000256
_081313E8:
	ldr r0, _08131408 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081313F4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813140C
	cmp r2, #2
	beq _08131410
	b _08131414
	.align 2, 0
_08131408: .4byte 0x030046A4
_0813140C:
	ldrb r0, [r4, #4]
	b _08131412
_08131410:
	ldrb r0, [r4]
_08131412:
	subs r1, r1, r0
_08131414:
	ldr r3, _0813142C @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08131430 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x2a]
	movs r6, #1
	str r6, [sp, #0x3c]
	b _08131474
	.align 2, 0
_0813142C: .4byte 0x00000472
_08131430: .4byte 0x0000FFFF
_08131434:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _08131498 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _0813149C @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081314A0 @ =0x000004B4
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
	str r0, [sp, #0x3c]
	str r5, [sp, #0x10c]
	str r4, [sp, #0x110]
	str r3, [sp, #0x114]
_08131474:
	movs r0, #0x4e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _081314BE
	bl VM_GetPC
	cmp r0, #0
	beq _081314A4
	bl Script_GetValue
	adds r4, r0, #0
	b _081314A6
	.align 2, 0
_08131498: .4byte 0x00000251
_0813149C: .4byte 0x00000252
_081314A0: .4byte 0x000004B4
_081314A4:
	movs r4, #0x30
_081314A6:
	bl VM_GetPC
	cmp r0, #0
	beq _081314B8
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081314BA
_081314B8:
	movs r5, #0x40
_081314BA:
	mov r8, r4
	b _081314C4
_081314BE:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081314C4:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _081314FC
	bl VM_GetPC
	cmp r0, #0
	beq _081314DE
	bl Script_GetValue
	adds r6, r0, #0
	b _081314E0
_081314DE:
	movs r6, #0
_081314E0:
	bl VM_GetPC
	cmp r0, #0
	beq _081314F0
	bl Script_GetValue
	adds r1, r0, #0
	b _081314F2
_081314F0:
	movs r1, #0
_081314F2:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08131506
_081314FC:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08131506:
	movs r0, #0x61
	bl prepare_08231510
	ldr r1, _0813178C @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x128]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x104]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x98]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x94]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x118]
	lsls r4, r4, #0x10
	str r4, [sp, #0xb4]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0xc0]
	lsls r6, r6, #0x10
	str r6, [sp, #0xc4]
	lsls r5, r5, #0x10
	str r5, [sp, #0xbc]
	ldr r4, _08131790 @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x120]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0xb0]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x48]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xc8]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xcc]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x4c]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x50]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x44]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x78]
	ldr r1, _08131794 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x6c]
	ldr r2, _08131798 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x70]
	ldr r3, _0813179C @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x74]
	ldr r4, _081317A0 @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x88]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x90]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x11c]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x12c]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x134]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x144]
	ldr r4, _081317A4 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x148]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x15c]
	ldr r6, _081317A8 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x160]
	ldr r1, _081317AC @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x168]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x16c]
	ldr r3, _081317B0 @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x170]
	ldr r4, _081317B4 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x178]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x164]
	ldr r6, _081317B8 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0x124]
	ldr r1, _081317BC @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x19c]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x1a0]
	ldr r3, _081317C0 @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xd4]
	ldr r4, _081317C4 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x1a4]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x18c]
	ldr r6, _081317C8 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x180]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x190]
	ldr r2, _081317CC @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x194]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x198]
	ldr r4, _081317D0 @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x1a8]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x1ac]
	ldr r6, _081317D4 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x158]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x184]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x17c]
	ldr r3, _081317D8 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x188]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x174]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x14c]
	ldr r6, _081317DC @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x1b0]
	ldr r1, _081317E0 @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0x130]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x40]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x154]
	ldr r4, _081317E4 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0x138]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x13c]
	ldr r6, _081317E8 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x140]
	ldr r1, _081317EC @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x150]
	ldr r2, _081317F0 @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xd0]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x9c]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0xa0]
	ldr r5, _081317F4 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x80]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x54]
	ldr r1, _081317F8 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r2, _081317FC @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	ldr r3, _08131800 @ =0x0000046D
	adds r3, r7, r3
	str r3, [sp, #0x64]
	ldr r4, _08131804 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x60]
	ldr r5, _08131808 @ =0x00000553
	adds r5, r7, r5
	str r5, [sp, #0xd8]
	movs r6, #0xaf
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x108]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xa8]
	movs r2, #0x92
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x7c]
	movs r3, #0xea
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0xac]
	ldr r4, _0813180C @ =0x00000572
	adds r4, r7, r4
	str r4, [sp, #0x100]
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r5, r7, r5
	str r5, [sp, #0xa4]
	movs r6, #0xae
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xfc]
	ldr r1, _08131810 @ =0x0000055C
	adds r1, r7, r1
	str r1, [sp, #0xdc]
	movs r2, #0xac
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xe0]
	ldr r3, _08131814 @ =0x00000564
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	ldr r4, _08131818 @ =0x00000565
	adds r4, r7, r4
	str r4, [sp, #0xe8]
	ldr r5, _0813181C @ =0x00000566
	adds r5, r7, r5
	str r5, [sp, #0xec]
	ldr r6, _08131820 @ =0x00000567
	adds r6, r7, r6
	str r6, [sp, #0xf0]
	movs r1, #0xad
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf4]
	ldr r2, _08131824 @ =0x0000056C
	adds r2, r7, r2
	str r2, [sp, #0xf8]
	cmp r0, #0
	bne _0813175C
	b _08131880
_0813175C:
	movs r3, #0
	mov sl, r3
	movs r4, #0x8d
	lsls r4, r4, #2
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r5, r5, r7
	mov r8, r5
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r5, r7, r6
	movs r0, #0x89
	lsls r0, r0, #2
	adds r4, r7, r0
_0813177C:
	bl VM_GetPC
	cmp r0, #0
	beq _08131828
	bl Script_GetValue
	b _0813182A
	.align 2, 0
_0813178C: .4byte 0x0000025D
_08131790: .4byte 0x0000025A
_08131794: .4byte 0x0000047A
_08131798: .4byte 0x0000047C
_0813179C: .4byte 0x0000047E
_081317A0: .4byte 0x000004A4
_081317A4: .4byte 0x000005A4
_081317A8: .4byte 0x000005C4
_081317AC: .4byte 0x000005CC
_081317B0: .4byte 0x000005D4
_081317B4: .4byte 0x000005DC
_081317B8: .4byte 0x00000584
_081317BC: .4byte 0x00000604
_081317C0: .4byte 0x0000021D
_081317C4: .4byte 0x0000060C
_081317C8: .4byte 0x000005E4
_081317CC: .4byte 0x000005FC
_081317D0: .4byte 0x00000614
_081317D4: .4byte 0x000005BC
_081317D8: .4byte 0x000005EC
_081317DC: .4byte 0x00000624
_081317E0: .4byte 0x0000058C
_081317E4: .4byte 0x00000594
_081317E8: .4byte 0x0000059C
_081317EC: .4byte 0x000005B4
_081317F0: .4byte 0x00000543
_081317F4: .4byte 0x00000496
_081317F8: .4byte 0x00000469
_081317FC: .4byte 0x0000046A
_08131800: .4byte 0x0000046D
_08131804: .4byte 0x0000046B
_08131808: .4byte 0x00000553
_0813180C: .4byte 0x00000572
_08131810: .4byte 0x0000055C
_08131814: .4byte 0x00000564
_08131818: .4byte 0x00000565
_0813181C: .4byte 0x00000566
_08131820: .4byte 0x00000567
_08131824: .4byte 0x0000056C
_08131828:
	movs r0, #0x18
_0813182A:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _0813183C
	bl Script_GetValue
	b _0813183E
_0813183C:
	movs r0, #0x18
_0813183E:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08131850
	bl Script_GetValue
	b _08131852
_08131850:
	movs r0, #0
_08131852:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08131864
	bl Script_GetValue
	b _08131866
_08131864:
	movs r0, #0
_08131866:
	strh r0, [r6]
	movs r1, #2
	add sb, r1
	movs r2, #4
	add r8, r2
	adds r5, #2
	adds r4, #2
	movs r3, #1
	add sl, r3
	mov r6, sl
	cmp r6, #3
	bgt _08131880
	b _0813177C
_08131880:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _081318CC
	bl VM_GetPC
	cmp r0, #0
	beq _0813189A
	bl Script_GetValue
	adds r4, r0, #0
	b _0813189E
_0813189A:
	movs r4, #0x96
	lsls r4, r4, #1
_0813189E:
	bl VM_GetPC
	cmp r0, #0
	beq _081318AE
	bl Script_GetValue
	adds r6, r0, #0
	b _081318B2
_081318AE:
	movs r6, #0x96
	lsls r6, r6, #1
_081318B2:
	bl VM_GetPC
	cmp r0, #0
	beq _081318C0
	bl Script_GetValue
	b _081318C6
_081318C0:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r1, #0
_081318C6:
	ldr r2, [sp, #0x104]
	strh r0, [r2]
	b _081318D4
_081318CC:
	movs r4, #0
	movs r6, #0
	ldr r3, [sp, #0x104]
	strh r6, [r3]
_081318D4:
	movs r0, #0x62
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _081318EC
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x8c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_081318EC:
	movs r0, #0x46
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x98]
	strh r0, [r1]
	movs r0, #0x52
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, [sp, #0x94]
	strh r0, [r2]
	movs r0, #0x41
	bl prepare_08231510
	cmp r0, #0
	beq _081319BC
	bl VM_GetPC
	cmp r0, #0
	beq _0813191C
	bl Script_GetValue
	b _0813191E
_0813191C:
	movs r0, #0
_0813191E:
	ldr r3, [sp, #0x118]
	strh r0, [r3]
	ldrh r0, [r3]
	cmp r0, #0
	blt _0813192C
	asrs r1, r0, #1
	b _08131932
_0813192C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08131932:
	ldr r5, _08131948 @ =0x00000546
	adds r0, r7, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0813194C
	bl Script_GetValue
	b _0813194E
	.align 2, 0
_08131948: .4byte 0x00000546
_0813194C:
	movs r0, #0
_0813194E:
	movs r2, #0xc3
	lsls r2, r2, #1
	adds r1, r7, r2
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08131964
	bl Script_GetValue
	b _08131966
_08131964:
	movs r0, #0
_08131966:
	ldr r3, _0813197C @ =0x00000187
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08131980
	bl Script_GetValue
	adds r1, r0, #0
	b _08131982
	.align 2, 0
_0813197C: .4byte 0x00000187
_08131980:
	movs r1, #0
_08131982:
	movs r5, #0xc4
	lsls r5, r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08131998
	bl Script_GetValue
	b _0813199A
_08131998:
	movs r0, #0
_0813199A:
	movs r2, #0xc5
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _081319B2
	bl Script_GetValue
	adds r1, r0, #0
	b _081319B4
_081319B2:
	movs r1, #0
_081319B4:
	movs r3, #0xc6
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r1, [r0]
_081319BC:
	ldr r5, [sp, #0x118]
	ldrh r1, [r5]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r6, [sp, #0xb4]
	lsrs r2, r6, #0x10
	ldr r0, [sp, #0xc0]
	lsrs r3, r0, #0x10
	ldr r1, [sp, #0xc4]
	lsrs r0, r1, #0x10
	str r0, [sp]
	ldr r4, [sp, #0xbc]
	lsrs r0, r4, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl prepare_08231510
	cmp r0, #0
	beq _08131A1E
	movs r5, #0xe8
	lsls r5, r5, #1
	adds r6, r7, r5
	bl VM_GetPC
	cmp r0, #0
	beq _08131A04
	bl Script_GetValue
	b _08131A06
_08131A04:
	movs r0, #0
_08131A06:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08131A16
	bl Script_GetValue
	b _08131A18
_08131A16:
	movs r0, #0
_08131A18:
	ldr r6, _08131A80 @ =0x00000189
	adds r1, r7, r6
	strb r0, [r1]
_08131A1E:
	movs r0, #0x4b
	movs r1, #2
	bl Script_GetKeywordValue
	ldr r1, [sp, #0x120]
	strh r0, [r1]
	movs r0, #0x48
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08131A42
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r2, [sp, #0x8c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08131A42:
	movs r0, #0x4c
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08131A5A
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r3, [sp, #0x8c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
_08131A5A:
	ldr r4, [sp, #0xb0]
	lsrs r1, r4, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x38]
	add r2, sp, #0x28
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r5, [sp, #0x68]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08131A84
	movs r0, #1
	b _08131A86
	.align 2, 0
_08131A80: .4byte 0x00000189
_08131A84:
	movs r0, #0
_08131A86:
	cmp r0, #0
	beq _08131A96
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08131AC0 @ =FUN_080f48ac
	ldr r1, [sp, #0x38]
	bl FUN_0807f558
_08131A96:
	ldr r6, [sp, #0x128]
	ldrb r0, [r6]
	movs r1, #0
	cmp r0, #0
	bne _08131AA2
	ldr r1, [r7, #0x44]
_08131AA2:
	ldr r0, [sp, #0x38]
	bl FUN_0823b46c
	ldr r1, [sp, #0xb8]
	ldrb r0, [r1]
	cmp r0, #0x15
	bne _08131AC4
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x48]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08131AD0
	.align 2, 0
_08131AC0: .4byte FUN_080f48ac
_08131AC4:
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x48]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08131AD0:
	ldr r2, [sp, #0xb8]
	ldrb r1, [r2]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08131B1E
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08131B1E
	cmp r0, #0x16
	beq _08131B1E
	cmp r0, #0x14
	beq _08131B1E
	cmp r0, #9
	beq _08131B1E
	cmp r0, #0x19
	beq _08131B1E
	cmp r0, #0x1a
	beq _08131B1E
	cmp r0, #0xd
	beq _08131B1E
	cmp r0, #0x1b
	beq _08131B1E
	cmp r0, #0x1f
	beq _08131B1E
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r3, [sp, #0x10c]
	ldrb r2, [r3]
	ldr r4, [sp, #0x110]
	ldrb r3, [r4]
	ldr r5, [sp, #0x114]
	ldrb r0, [r5]
	str r0, [sp]
	ldr r0, [sp, #0x38]
	bl FUN_0823b490
_08131B1E:
	movs r1, #8
	ldr r6, [sp, #0x68]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08131B2E
	movs r0, #1
	b _08131B30
_08131B2E:
	movs r0, #0
_08131B30:
	cmp r0, #0
	beq _08131B3E
	ldr r1, [sp, #0xcc]
	ldr r0, [r1]
	ldr r2, [sp, #0xc8]
	str r0, [r2]
	b _08131B50
_08131B3E:
	ldr r3, [sp, #0xcc]
	ldr r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r4, [sp, #0xc8]
	str r0, [r4]
_08131B50:
	ldrh r0, [r7]
	ldr r5, [sp, #0x4c]
	strh r0, [r5]
	ldr r6, [sp, #0x44]
	ldr r0, [sp, #0x50]
	str r6, [r0]
	ldr r1, [sp, #0x3c]
	cmp r1, #0
	beq _08131B7A
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
	ldr r2, [sp, #0x38]
	strb r0, [r2, #5]
_08131B7A:
	movs r4, #0x8f
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x78]
	strh r0, [r3]
	ldr r6, [sp, #0x6c]
	strh r4, [r6]
	ldr r0, [sp, #0x70]
	strh r5, [r0]
	ldrh r0, [r3]
	adds r0, #0x8f
	ldr r1, [sp, #0x74]
	strh r0, [r1]
	ldrh r1, [r6]
	ldrh r0, [r3]
	adds r1, r1, r0
	ldr r2, [sp, #0x128]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08131BB4
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _08131BC0
_08131BB4:
	ldr r2, [r7, #0x44]
	ldr r0, _08131BF8 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08131BC0:
	ldr r3, [sp, #0x128]
	ldrb r0, [r3]
	cmp r0, #1
	bne _08131C10
	ldr r4, [sp, #0xb8]
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08131BFC
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
	b _08131C06
	.align 2, 0
_08131BF8: .4byte 0x03003584
_08131BFC:
	ldr r5, [sp, #0xb8]
	ldrb r0, [r5]
	bl FUN_080ecf60
	adds r4, r0, #1
_08131C06:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08131C10:
	adds r0, r7, #0
	bl FUN_081300f4
	movs r0, #0x66
	movs r1, #0
	bl Script_GetKeywordValue
	str r0, [sp, #0x34]
	movs r0, #0x54
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	beq _08131C3C
	ldr r6, [sp, #0x30]
	movs r0, #0xcc
	lsls r0, r0, #3
	adds r2, r6, r0
	ldrh r1, [r2]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r2]
_08131C3C:
	ldr r1, [sp, #0x30]
	ldr r2, _08131D98 @ =0x00000664
	adds r0, r1, r2
	movs r3, #0xd1
	lsls r3, r3, #3
	adds r1, r1, r3
	mov r8, r1
	ldr r4, _08131D9C @ =FUN_081310b8
	mov sb, r4
	ldr r5, _08131DA0 @ =FUN_0813107c
	mov sl, r5
	ldr r6, _08131DA4 @ =FUN_0812eab4
	mov ip, r6
	movs r4, #0
	ldr r5, _08131DA8 @ =FUN_0812f3f8
	ldr r3, _08131DAC @ =FUN_080f62b0
	ldr r1, _08131DB0 @ =FUN_080f62ac
	str r1, [sp, #0x1b4]
	movs r2, #0x80
	lsls r2, r2, #6
	ldr r6, [sp, #0x84]
	ldr r1, [r6]
	orrs r1, r2
	str r1, [r6]
	ldr r1, [sp, #0x88]
	str r0, [r1]
	mov r2, r8
	ldr r6, [sp, #0x90]
	str r2, [r6]
	mov r1, sb
	ldr r2, [sp, #0x11c]
	str r1, [r2]
	mov r6, sl
	ldr r1, [sp, #0x12c]
	str r6, [r1]
	mov r2, ip
	ldr r6, [sp, #0x134]
	str r2, [r6]
	ldr r1, _08131DB4 @ =FUN_0812ea6c
	ldr r2, [sp, #0x144]
	str r1, [r2]
	ldr r6, _08131DB8 @ =FUN_0812ea90
	ldr r1, [sp, #0x148]
	str r6, [r1]
	ldr r2, _08131DBC @ =FUN_0812f1b4
	ldr r6, [sp, #0x15c]
	str r2, [r6]
	ldr r1, [sp, #0x160]
	str r3, [r1]
	ldr r2, [sp, #0x168]
	str r5, [r2]
	ldr r3, _08131DC0 @ =FUN_0812f5f4
	ldr r5, [sp, #0x16c]
	str r3, [r5]
	ldr r1, _08131DC4 @ =FUN_080f44f4
	ldr r6, [sp, #0x170]
	str r1, [r6]
	ldr r1, _08131DC8 @ =FUN_080f410c
	ldr r2, [sp, #0x178]
	str r1, [r2]
	ldr r3, [sp, #0x164]
	str r4, [r3]
	ldr r5, _08131DCC @ =FUN_0812f1b8
	ldr r6, [sp, #0x124]
	str r5, [r6]
	ldr r1, [sp, #0x1b4]
	ldr r2, [sp, #0x19c]
	str r1, [r2]
	ldr r1, _08131DD0 @ =FUN_080f0430
	ldr r3, [sp, #0x1a0]
	str r1, [r3]
	movs r6, #1
	ldr r5, [sp, #0xd4]
	strb r6, [r5]
	ldr r1, _08131DD4 @ =0x085AD470
	ldr r2, [sp, #0x1a4]
	str r1, [r2]
	ldr r1, _08131DD8 @ =FUN_080e73c8
	ldr r3, [sp, #0x18c]
	str r1, [r3]
	ldr r5, [sp, #0x180]
	str r4, [r5]
	ldr r6, [sp, #0x190]
	str r4, [r6]
	ldr r1, [sp, #0x194]
	str r4, [r1]
	ldr r2, [sp, #0x198]
	str r4, [r2]
	ldr r3, [sp, #0x1a8]
	str r4, [r3]
	ldr r1, _08131DDC @ =FUN_080f0320
	ldr r5, [sp, #0x1ac]
	str r1, [r5]
	ldr r1, _08131DE0 @ =FUN_080eff14
	ldr r6, [sp, #0x158]
	str r1, [r6]
	ldr r1, _08131DE4 @ =FUN_080e72b0
	ldr r2, [sp, #0x184]
	str r1, [r2]
	ldr r3, [sp, #0x17c]
	str r4, [r3]
	ldr r1, _08131DE8 @ =FUN_080f47c8
	ldr r5, [sp, #0x188]
	str r1, [r5]
	ldr r1, _08131DEC @ =FUN_080f54e4
	ldr r6, [sp, #0x174]
	str r1, [r6]
	ldr r1, [sp, #0x14c]
	str r4, [r1]
	ldr r1, _08131DF0 @ =FUN_080f6e64
	ldr r2, [sp, #0x1b0]
	str r1, [r2]
	ldr r1, _08131DF4 @ =FUN_080f64f0
	ldr r3, [sp, #0x130]
	str r1, [r3]
	ldr r1, _08131DF8 @ =FUN_080f84d4
	ldr r5, [sp, #0x40]
	str r1, [r5]
	ldr r1, _08131DFC @ =FUN_080f624c
	ldr r6, [sp, #0x154]
	str r1, [r6]
	ldr r1, _08131E00 @ =FUN_080f56ec
	ldr r2, [sp, #0x138]
	str r1, [r2]
	ldr r1, _08131E04 @ =FUN_080f5b34
	ldr r3, [sp, #0x13c]
	str r1, [r3]
	ldr r1, _08131E08 @ =FUN_080f5fac
	ldr r5, [sp, #0x140]
	str r1, [r5]
	ldr r6, [sp, #0x150]
	str r4, [r6]
	movs r1, #0x28
	ldr r2, [sp, #0xd0]
	strb r1, [r2]
	ldr r1, [sp, #0x44]
	bl FUN_082362fc
	adds r0, r7, #0
	bl FUN_080e6204
	ldr r3, _08131E0C @ =0x0000060C
	adds r1, r7, r3
	ldr r0, _08131E10 @ =0x085AD710
	str r0, [r1]
	movs r5, #0xbf
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08131E14 @ =FUN_08130190
	str r0, [r1]
	ldr r6, _08131E18 @ =0x000005AC
	adds r0, r7, r6
	str r4, [r0]
	movs r1, #0xb6
	lsls r1, r1, #3
	adds r0, r7, r1
	str r4, [r0]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _08131E1C @ =FUN_0812f358
	str r0, [r1]
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08131E24
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08131E20 @ =FUN_08130d34
	b _08131E2C
	.align 2, 0
_08131D98: .4byte 0x00000664
_08131D9C: .4byte FUN_081310b8
_08131DA0: .4byte FUN_0813107c
_08131DA4: .4byte FUN_0812eab4
_08131DA8: .4byte FUN_0812f3f8
_08131DAC: .4byte FUN_080f62b0
_08131DB0: .4byte FUN_080f62ac
_08131DB4: .4byte FUN_0812ea6c
_08131DB8: .4byte FUN_0812ea90
_08131DBC: .4byte FUN_0812f1b4
_08131DC0: .4byte FUN_0812f5f4
_08131DC4: .4byte FUN_080f44f4
_08131DC8: .4byte FUN_080f410c
_08131DCC: .4byte FUN_0812f1b8
_08131DD0: .4byte FUN_080f0430
_08131DD4: .4byte 0x085AD470
_08131DD8: .4byte FUN_080e73c8
_08131DDC: .4byte FUN_080f0320
_08131DE0: .4byte FUN_080eff14
_08131DE4: .4byte FUN_080e72b0
_08131DE8: .4byte FUN_080f47c8
_08131DEC: .4byte FUN_080f54e4
_08131DF0: .4byte FUN_080f6e64
_08131DF4: .4byte FUN_080f64f0
_08131DF8: .4byte FUN_080f84d4
_08131DFC: .4byte FUN_080f624c
_08131E00: .4byte FUN_080f56ec
_08131E04: .4byte FUN_080f5b34
_08131E08: .4byte FUN_080f5fac
_08131E0C: .4byte 0x0000060C
_08131E10: .4byte 0x085AD710
_08131E14: .4byte FUN_08130190
_08131E18: .4byte 0x000005AC
_08131E1C: .4byte FUN_0812f358
_08131E20: .4byte FUN_08130d34
_08131E24:
	movs r5, #0xc1
	lsls r5, r5, #3
	adds r1, r7, r5
	ldr r0, _08131E70 @ =FUN_08130ac4
_08131E2C:
	str r0, [r1]
	movs r1, #0xa0
	lsls r1, r1, #0xf
	ldr r6, [sp, #0x84]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r1, #8
	ldr r2, [sp, #0x8c]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x49
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r3, [sp, #0x9c]
	strh r0, [r3]
	movs r0, #0x47
	bl prepare_08231510
	cmp r0, #0
	beq _08131E7E
	movs r4, #0xce
	lsls r4, r4, #1
	adds r5, r7, r4
	movs r4, #4
_08131E62:
	bl VM_GetPC
	cmp r0, #0
	beq _08131E74
	bl Script_GetValue
	b _08131E76
	.align 2, 0
_08131E70: .4byte FUN_08130ac4
_08131E74:
	movs r0, #0
_08131E76:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _08131E62
_08131E7E:
	movs r0, #0x44
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r5, [sp, #0xa0]
	strh r0, [r5]
	movs r0, #0x75
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r6, [sp, #0x80]
	strh r0, [r6]
	cmp r2, #0
	beq _08131EB6
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r3, [sp, #0x84]
	ldr r1, [r3]
	orrs r1, r0
	str r1, [r3]
	cmp r2, #2
	bne _08131EB6
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r3]
_08131EB6:
	movs r2, #0
	movs r1, #4
	ldr r4, [sp, #0x68]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08131EC8
	movs r0, #1
	b _08131ECA
_08131EC8:
	movs r0, #0
_08131ECA:
	cmp r0, #0
	beq _08131EDC
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r5, [sp, #0x8c]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	movs r2, #1
_08131EDC:
	cmp r2, #1
	beq _08131F14
	movs r1, #0
	ldr r6, [sp, #0x54]
	strb r1, [r6]
	ldr r0, [sp, #0x58]
	strb r1, [r0]
	ldr r2, [sp, #0x5c]
	strb r1, [r2]
	ldr r3, _08131F24 @ =0x00000484
	adds r0, r7, r3
	str r1, [r0]
	ldr r4, _08131F28 @ =0x0000046C
	adds r0, r7, r4
	movs r2, #1
	strb r2, [r0]
	ldr r5, [sp, #0x148]
	ldr r0, [r5]
	ldr r6, [sp, #0x64]
	strb r2, [r6]
	ldr r2, [sp, #0x60]
	strb r1, [r2]
	ldr r3, [sp, #0xd8]
	strb r1, [r3]
	ldr r4, [sp, #0x108]
	str r0, [r4]
	ldr r5, [sp, #0xa8]
	strh r1, [r5]
_08131F14:
	movs r1, #2
	ldr r6, [sp, #0x68]
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08131F2C
	movs r0, #1
	b _08131F2E
	.align 2, 0
_08131F24: .4byte 0x00000484
_08131F28: .4byte 0x0000046C
_08131F2C:
	movs r0, #0
_08131F2E:
	cmp r0, #0
	beq _08131F48
	ldr r0, _08131F44 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, [sp, #0x7c]
	strh r0, [r2]
	b _08131F52
	.align 2, 0
_08131F44: .4byte 0x030046A0
_08131F48:
	ldr r0, [sp, #0x44]
	bl FUN_08241574
	ldr r3, [sp, #0x7c]
	strh r0, [r3]
_08131F52:
	movs r1, #0x40
	ldr r4, [sp, #0x68]
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08131F62
	movs r0, #1
	b _08131F64
_08131F62:
	movs r0, #0
_08131F64:
	cmp r0, #0
	beq _08131F74
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08131F98 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08131F74:
	movs r0, #0x53
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	bne _08131FA6
	ldr r0, _08131F9C @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x92
	lsls r5, r5, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r6, [sp, #0x7c]
	ldrh r6, [r6]
	cmp r0, r6
	bne _08131FA0
	movs r0, #1
	b _08131FA2
	.align 2, 0
_08131F98: .4byte 0xFFFFFEFF
_08131F9C: .4byte 0x030046A0
_08131FA0:
	movs r0, #0
_08131FA2:
	cmp r0, #0
	bne _08131FAE
_08131FA6:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_08131FAE:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r1, [sp, #0x128]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08132096
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
	beq _08131FF0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08131FF8
_08131FF0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08131FF8:
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
	beq _0813201C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08132024
_0813201C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08132024:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _0813205C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r5, [r4, #7]
	cmp r0, r5
	blo _081320A0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08132060
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08132054
	ldrb r0, [r4, #5]
_08132054:
	subs r0, #1
	strh r0, [r4, #8]
	b _08132070
	.align 2, 0
_0813205C: .4byte 0x0000FFFF
_08132060:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r6, [r4, #5]
	cmp r0, r6
	blo _08132070
	strh r1, [r4, #8]
_08132070:
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
	bne _081320A0
	movs r0, #1
	strb r0, [r4, #7]
	b _081320A0
_08132096:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_081320A0:
	movs r0, #0
	ldr r1, [sp, #0xac]
	str r0, [r1]
	ldr r0, _081320B8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081320BC
	movs r0, #1
	b _081320BE
	.align 2, 0
_081320B8: .4byte 0x030047A4
_081320BC:
	movs r0, #0
_081320BE:
	cmp r0, #0
	bne _081320FE
	ldr r2, [sp, #0xb8]
	ldrb r1, [r2]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081320E6
	adds r0, r1, #0
	cmp r0, #7
	beq _081320E6
	cmp r0, #6
	beq _081320E6
	cmp r0, #0x15
	beq _081320E6
	cmp r0, #0x14
	beq _081320E6
	cmp r0, #0x17
	bne _081320FE
_081320E6:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r3, [sp, #0x68]
	ldrh r1, [r3]
	orrs r0, r1
	strh r0, [r3]
_081320FE:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_081300d0
	ldr r4, [sp, #0x34]
	cmp r4, #0
	beq _081321B8
	movs r5, #0xdf
	lsls r5, r5, #1
	adds r0, r7, r5
	movs r4, #0
	movs r2, #0
	mov r6, sp
	ldrh r6, [r6, #0x34]
	strh r6, [r0]
	movs r0, #0xde
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #2
	strh r0, [r1]
	ldr r1, _081321A4 @ =FUN_0812edf8
	movs r0, #0x22
	movs r5, #1
	ldr r3, [sp, #0x64]
	strb r5, [r3]
	ldr r6, [sp, #0x60]
	strb r4, [r6]
	ldr r3, [sp, #0xd8]
	strb r0, [r3]
	ldr r6, [sp, #0x108]
	str r1, [r6]
	ldr r0, [sp, #0xa8]
	strh r2, [r0]
	movs r0, #3
	ldr r1, [sp, #0x54]
	strb r0, [r1]
	ldr r3, [sp, #0x58]
	strb r4, [r3]
	ldr r6, [sp, #0x5c]
	strb r4, [r6]
	ldr r1, _081321A8 @ =0x00000484
	adds r0, r7, r1
	str r2, [r0]
	ldr r3, _081321AC @ =0x0000046C
	adds r0, r7, r3
	strb r5, [r0]
	movs r4, #0xaa
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r1, #0x60
	str r1, [sp]
	movs r1, #0x64
	str r1, [sp, #4]
	movs r1, #0xa0
	lsls r1, r1, #4
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	movs r1, #5
	str r1, [sp, #0x10]
	str r5, [sp, #0x14]
	str r2, [sp, #0x18]
	ldr r1, [sp, #0x44]
	movs r2, #0x40
	movs r3, #0x10
	bl FUN_08013ba8
	ldr r6, _081321B0 @ =0x0000044C
	adds r1, r7, r6
	strb r0, [r1]
	ldr r1, _081321B4 @ =0x0000044D
	adds r0, r7, r1
	strb r5, [r0]
	ldr r3, [sp, #0x30]
	movs r4, #0xcc
	lsls r4, r4, #3
	adds r2, r3, r4
	ldrh r0, [r2]
	movs r1, #1
	orrs r0, r1
	strh r0, [r2]
	b _0813221A
	.align 2, 0
_081321A4: .4byte FUN_0812edf8
_081321A8: .4byte 0x00000484
_081321AC: .4byte 0x0000046C
_081321B0: .4byte 0x0000044C
_081321B4: .4byte 0x0000044D
_081321B8:
	ldr r1, _081322A0 @ =FUN_080e68d8
	movs r0, #0xe
	movs r3, #1
	ldr r5, [sp, #0x64]
	strb r3, [r5]
	add r6, sp, #0x34
	ldrb r2, [r6]
	ldr r6, [sp, #0x60]
	strb r2, [r6]
	ldr r2, [sp, #0xd8]
	strb r0, [r2]
	ldr r4, [sp, #0x108]
	str r1, [r4]
	movs r5, #0
	mov r6, sp
	ldrh r0, [r6, #0x34]
	ldr r6, [sp, #0xa8]
	strh r0, [r6]
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	movs r2, #7
	mov r8, r2
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r4, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _081322A4 @ =0x00000551
	adds r0, r7, r2
	strb r5, [r0]
	ldr r4, _081322A8 @ =0x00000552
	adds r0, r7, r4
	mov r5, r8
	strb r5, [r0]
	ldr r6, _081322AC @ =0x0000044C
	adds r0, r7, r6
	strb r3, [r0]
	ldr r1, _081322B0 @ =0x0000044D
	adds r0, r7, r1
	strb r3, [r0]
_0813221A:
	ldr r2, [sp, #0x30]
	ldr r3, _081322B4 @ =0x00000662
	adds r1, r2, r3
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r4, [sp, #0x68]
	ldrh r0, [r4]
	ldr r5, [sp, #0x100]
	strh r0, [r5]
	ldr r6, [sp, #0xa4]
	ldrh r0, [r6]
	ldr r1, [sp, #0xfc]
	strh r0, [r1]
	ldr r2, [sp, #0x84]
	ldr r0, [r2]
	ldr r3, [sp, #0xdc]
	str r0, [r3]
	ldr r4, [sp, #0x8c]
	ldr r0, [r4]
	ldr r5, [sp, #0xe0]
	str r0, [r5]
	ldrb r0, [r7, #5]
	ldr r6, [sp, #0xe4]
	strb r0, [r6]
	ldr r1, [sp, #0x54]
	ldrb r0, [r1]
	ldr r2, [sp, #0xe8]
	strb r0, [r2]
	ldr r3, [sp, #0x58]
	ldrb r0, [r3]
	ldr r4, [sp, #0xec]
	strb r0, [r4]
	ldr r5, [sp, #0x5c]
	ldrb r0, [r5]
	ldr r6, [sp, #0xf0]
	strb r0, [r6]
	ldr r1, [sp, #0x108]
	ldr r0, [r1]
	ldr r2, [sp, #0xf4]
	str r0, [r2]
	ldr r3, [sp, #0xd8]
	ldrb r0, [r3]
	ldr r4, [sp, #0xf8]
	strb r0, [r4]
	ldr r5, _081322B8 @ =0x0000057C
	adds r1, r7, r5
	ldr r0, _081322BC @ =FUN_080f09e0
	str r0, [r1]
	ldr r6, _081322C0 @ =0x0000061C
	adds r1, r7, r6
	ldr r0, _081322C4 @ =FUN_081310ec
	str r0, [r1]
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081322C8 @ =FUN_081310f8
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081322CC
	movs r0, #0
	b _081322D0
	.align 2, 0
_081322A0: .4byte FUN_080e68d8
_081322A4: .4byte 0x00000551
_081322A8: .4byte 0x00000552
_081322AC: .4byte 0x0000044C
_081322B0: .4byte 0x0000044D
_081322B4: .4byte 0x00000662
_081322B8: .4byte 0x0000057C
_081322BC: .4byte FUN_080f09e0
_081322C0: .4byte 0x0000061C
_081322C4: .4byte FUN_081310ec
_081322C8: .4byte FUN_081310f8
_081322CC:
	movs r0, #1
	rsbs r0, r0, #0
_081322D0:
	add sp, #0x1bc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemySpider_Create
EnemySpider_Create: @ 0x081322E0
	push {r4, r5, lr}
	movs r5, #0xd2
	lsls r5, r5, #3
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _0813230E
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemySpider_Init
	cmp r0, #0
	bge _0813230E
	adds r0, r4, #0
	bl FUN_081310f8
	adds r0, r4, #0
	bl Free
_0813230E:
	pop {r4, r5}
	pop {r0}
	bx r0
