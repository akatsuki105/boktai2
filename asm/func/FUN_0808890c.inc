	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r1, _08088990 @ =0x000001F5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _0808892A
	adds r0, r7, #0
	movs r1, #2
	bl Coffin_SetState
_0808892A:
	ldr r0, _08088994 @ =0x030047A4
	ldr r5, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r5, r0
	cmp r5, #0
	beq _0808893A
	b _08088BAE
_0808893A:
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x40
	bhi _0808894C
	b _08088ABC
_0808894C:
	ldr r1, _08088998 @ =0x0000032A
	adds r0, r7, r1
	movs r1, #2
	strh r1, [r0]
	adds r2, #8
	adds r1, r7, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	blt _08088964
	bl FUN_080dab9c
_08088964:
	ldr r0, _0808899C @ =0x0000039E
	adds r3, r7, r0
	ldrh r0, [r3]
	cmp r0, #2
	bne _080889A0
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r7, r1
	subs r1, #0x48
	strh r1, [r0]
	movs r5, #0xa5
	lsls r5, r5, #1
	adds r2, r7, r5
	movs r0, #0x20
	strh r0, [r2]
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r0, #1
	strh r0, [r3]
	b _080889C2
	.align 2, 0
_08088990: .4byte 0x000001F5
_08088994: .4byte 0x030047A4
_08088998: .4byte 0x0000032A
_0808899C: .4byte 0x0000039E
_080889A0:
	cmp r0, #1
	bne _080889C2
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #0x80
	strh r1, [r0]
	movs r0, #0xa5
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r0, #0x20
	strh r0, [r2]
	movs r2, #0xa6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	strh r5, [r3]
_080889C2:
	movs r5, #0x96
	lsls r5, r5, #1
	adds r4, r7, r5
	adds r1, r7, #0
	adds r1, #0x48
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r8, r0
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _08088A1E
	ldr r2, _08088A88 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08088A8C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08088A90 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r5, #0xd4
	adds r2, r7, r5
	ldrb r1, [r2]
	adds r1, r1, r0
	subs r1, #1
	movs r0, #7
	ands r1, r0
	strb r1, [r2]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08086024
_08088A1E:
	ldr r6, _08088A90 @ =0x0203B400
	ldr r0, _08088A88 @ =0x030046B8
	mov ip, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r3, _08088A8C @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r4, #0x3f
	ands r0, r4
	subs r0, #0x1f
	ldr r5, _08088A94 @ =0x0000031E
	adds r2, r7, r5
	strh r0, [r2]
	adds r1, #1
	ands r1, r3
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #0x1f
	ldr r2, _08088A98 @ =0x00000322
	adds r1, r7, r2
	strh r0, [r1]
	mov r5, r8
	ldrh r1, [r5]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08088A68
	adds r0, r7, #0
	bl FUN_08085880
_08088A68:
	ldr r1, _08088A9C @ =0x00000326
	adds r0, r7, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08088B5A
	lsrs r2, r0, #0x13
	mov r5, r8
	ldrh r1, [r5]
	adds r0, r2, #0
	adds r0, #0x40
	cmp r1, r0
	bge _08088AA0
	movs r0, #0x40
	strh r0, [r5]
	b _08088AA6
	.align 2, 0
_08088A88: .4byte 0x030046B8
_08088A8C: .4byte 0x000003FF
_08088A90: .4byte 0x0203B400
_08088A94: .4byte 0x0000031E
_08088A98: .4byte 0x00000322
_08088A9C: .4byte 0x00000326
_08088AA0:
	subs r0, r1, r2
	mov r1, r8
	strh r0, [r1]
_08088AA6:
	ldr r2, _08088AB8 @ =0x00000326
	adds r0, r7, r2
	movs r1, #0
	strh r1, [r0]
	movs r5, #0xc9
	lsls r5, r5, #2
	adds r0, r7, r5
	strh r1, [r0]
	b _08088B5A
	.align 2, 0
_08088AB8: .4byte 0x00000326
_08088ABC:
	lsrs r6, r1, #0x11
	cmp r6, #1
	bgt _08088AC4
	movs r6, #2
_08088AC4:
	ldr r0, _08088B84 @ =0x0203B400
	mov sl, r0
	ldr r1, _08088B88 @ =0x030046B8
	mov r8, r1
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _08088B8C @ =0x000003FF
	mov sb, r2
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	adds r1, r6, #0
	bl Mod
	asrs r4, r6, #1
	subs r0, r0, r4
	ldr r2, _08088B90 @ =0x0000031E
	adds r1, r7, r2
	strh r0, [r1]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	adds r1, r6, #0
	bl Mod
	subs r0, r0, r4
	ldr r2, _08088B94 @ =0x00000322
	adds r1, r7, r2
	strh r0, [r1]
	ldr r1, _08088B98 @ =0x0000032A
	adds r0, r7, r1
	strh r5, [r0]
	adds r2, #4
	adds r0, r7, r2
	strh r5, [r0]
	subs r1, #6
	adds r0, r7, r1
	strh r5, [r0]
	adds r2, #0x76
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r5, _08088B9C @ =0x0000FFFF
	adds r1, r5, #0
	ands r0, r1
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08088B5A
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	mov r2, sb
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r5, _08088B84 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08088B5A
	ldr r0, _08088BA0 @ =0x000002B9
	bl PlaySound_082406e0
_08088B5A:
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08088BAE
	ldrb r0, [r7, #0x1b]
	cmp r0, #1
	bne _08088BA8
	adds r0, r7, #0
	movs r1, #0xf
	bl Coffin_SetState
	ldr r2, _08088BA4 @ =0x00000402
	adds r1, r7, r2
	movs r0, #0x1e
	strh r0, [r1]
	b _08088BAE
	.align 2, 0
_08088B84: .4byte 0x0203B400
_08088B88: .4byte 0x030046B8
_08088B8C: .4byte 0x000003FF
_08088B90: .4byte 0x0000031E
_08088B94: .4byte 0x00000322
_08088B98: .4byte 0x0000032A
_08088B9C: .4byte 0x0000FFFF
_08088BA0: .4byte 0x000002B9
_08088BA4: .4byte 0x00000402
_08088BA8:
	adds r0, r7, #0
	bl FUN_080860cc
_08088BAE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
