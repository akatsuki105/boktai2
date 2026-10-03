	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x70
	str r0, [sp, #0x58]
	movs r2, #1
	ldr r3, _08094FF8 @ =0x0000216C
	adds r1, r0, r3
	movs r4, #5
_08094F9E:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r4, #1
	cmp r4, #0
	bge _08094F9E
	ldr r1, [sp, #0x58]
	movs r2, #0x9e
	lsls r2, r2, #4
	adds r0, r1, r2
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #5
	bne _08095028
	movs r4, #0
_08094FC4:
	movs r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r5, r0, #1
	adds r1, r5, #5
	asrs r0, r4, #1
	adds r6, r0, #5
	movs r0, #0
	adds r2, r6, #0
	bl FUN_0808a420
	adds r1, r0, #0
	cmp r4, #2
	bgt _08095000
	adds r7, r4, #1
	ldr r2, _08094FFC @ =0x0000F001
	adds r0, r2, #0
	movs r5, #4
_08094FEA:
	strh r0, [r1]
	adds r1, #2
	subs r5, #1
	cmp r5, #0
	bge _08094FEA
	b _0809501C
	.align 2, 0
_08094FF8: .4byte 0x0000216C
_08094FFC: .4byte 0x0000F001
_08095000:
	ldr r3, _08095024 @ =0x0000F071
	adds r0, r3, #0
	strh r0, [r1]
	movs r0, #0
	bl FUN_0807a6cc
	adds r2, r5, #7
	movs r1, #0
	str r1, [sp]
	movs r1, #0x64
	adds r3, r6, #0
	bl FUN_0808b30c
	adds r7, r4, #1
_0809501C:
	adds r4, r7, #0
	cmp r4, #3
	ble _08094FC4
	b _080952CE
	.align 2, 0
_08095024: .4byte 0x0000F071
_08095028:
	ldr r0, [sp, #0x58]
	ldr r1, _08095070 @ =0x00003AEB
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0xf
	bls _080950AC
	movs r4, #0
_08095036:
	adds r0, r4, #0
	add r1, sp, #4
	bl FUN_08242b28
	cmp r4, #3
	beq _0809504A
	add r0, sp, #4
	ldrb r0, [r0, #1]
	cmp r0, #3
	beq _08095074
_0809504A:
	add r0, sp, #4
	bl FUN_0807a6cc
	movs r1, #1
	ands r1, r4
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #1
	adds r2, #7
	asrs r3, r4, #1
	adds r3, #5
	movs r1, #0
	str r1, [sp]
	movs r1, #0x64
	bl FUN_0808b30c
	adds r7, r4, #1
	b _0809509E
	.align 2, 0
_08095070: .4byte 0x00003AEB
_08095074:
	movs r0, #1
	ands r0, r4
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, #5
	asrs r2, r4, #1
	adds r2, #5
	movs r0, #0
	bl FUN_0808a420
	adds r1, r0, #0
	adds r7, r4, #1
	ldr r3, _080950A8 @ =0x0000F001
	adds r2, r3, #0
	movs r0, #4
_08095094:
	strh r2, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _08095094
_0809509E:
	adds r4, r7, #0
	cmp r4, #3
	ble _08095036
	b _080952CE
	.align 2, 0
_080950A8: .4byte 0x0000F001
_080950AC:
	ldrb r0, [r4]
	bl GetWeaponID
	cmp r0, #0
	bne _08095128
	movs r4, #0
_080950B8:
	adds r0, r4, #0
	add r1, sp, #4
	bl FUN_08242b28
	cmp r4, #3
	beq _080950CC
	add r0, sp, #4
	ldrb r0, [r0, #1]
	cmp r0, #3
	beq _080950F0
_080950CC:
	add r0, sp, #4
	bl FUN_0807a6cc
	movs r1, #1
	ands r1, r4
	lsls r2, r1, #1
	adds r2, r2, r1
	lsls r2, r2, #1
	adds r2, #7
	asrs r3, r4, #1
	adds r3, #5
	movs r1, #0
	str r1, [sp]
	movs r1, #0x64
	bl FUN_0808b30c
	adds r7, r4, #1
	b _0809511A
_080950F0:
	movs r0, #1
	ands r0, r4
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, #5
	asrs r2, r4, #1
	adds r2, #5
	movs r0, #0
	bl FUN_0808a420
	adds r1, r0, #0
	adds r7, r4, #1
	ldr r0, _08095124 @ =0x0000F001
	adds r2, r0, #0
	movs r0, #4
_08095110:
	strh r2, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _08095110
_0809511A:
	adds r4, r7, #0
	cmp r4, #3
	ble _080950B8
	b _080952CE
	.align 2, 0
_08095124: .4byte 0x0000F001
_08095128:
	ldrb r0, [r4]
	add r1, sp, #4
	bl FUN_08242b14
	add r0, sp, #4
	bl FUN_0807a6cc
	str r0, [sp, #0x64]
	movs r1, #0x64
	bl Div
	add r5, sp, #0x28
	str r0, [sp, #0x28]
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	ldr r1, [sp, #0x64]
	subs r4, r1, r4
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [r5, #4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r4, r4, r1
	str r4, [r5, #8]
	add r0, sp, #4
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _0809517E
	cmp r0, #1
	bgt _08095172
	cmp r0, #0
	beq _08095178
	b _0809518A
_08095172:
	cmp r0, #2
	beq _08095184
	b _0809518A
_08095178:
	movs r2, #0
	str r2, [sp, #0x68]
	b _0809518E
_0809517E:
	movs r3, #1
	str r3, [sp, #0x68]
	b _0809518E
_08095184:
	movs r0, #2
	str r0, [sp, #0x68]
	b _0809518E
_0809518A:
	movs r1, #3
	str r1, [sp, #0x68]
_0809518E:
	movs r4, #0
	mov r2, sp
	adds r2, #0x34
	str r2, [sp, #0x6c]
_08095196:
	adds r0, r4, #0
	ldr r1, [sp, #0x6c]
	bl FUN_08242b28
	ldr r0, [sp, #0x6c]
	bl FUN_0807a6cc
	mov r8, r0
	movs r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r6, r0, #1
	adds r3, r6, #7
	mov sb, r3
	asrs r0, r4, #1
	adds r5, r0, #5
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	movs r1, #0x64
	mov r2, sb
	adds r3, r5, #0
	bl FUN_0808b30c
	cmp r4, #3
	bne _080951FC
	movs r0, #0
	movs r1, #0xb
	movs r2, #6
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r2, [sp, #0x6c]
	ldrb r0, [r2, #1]
	cmp r0, #4
	bne _080951EC
	ldr r3, _080951E8 @ =0x0000F071
	adds r0, r3, #0
	b _080951F0
	.align 2, 0
_080951E8: .4byte 0x0000F071
_080951EC:
	ldr r2, _080951F8 @ =0x0000F070
	adds r0, r2, #0
_080951F0:
	strh r0, [r1]
	movs r7, #4
	b _08095222
	.align 2, 0
_080951F8: .4byte 0x0000F070
_080951FC:
	ldr r3, [sp, #0x6c]
	ldrb r0, [r3, #1]
	adds r7, r4, #1
	cmp r0, #3
	bne _08095222
	adds r1, r6, #5
	movs r0, #0
	adds r2, r5, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, _080952E0 @ =0x0000F001
	adds r2, r0, #0
	movs r0, #4
_08095218:
	strh r2, [r1]
	adds r1, #2
	subs r0, #1
	cmp r0, #0
	bge _08095218
_08095222:
	movs r0, #0
	movs r6, #0
	ldr r1, [sp, #0x68]
	cmp r4, r1
	bne _0809523C
	ldr r2, [sp, #0x64]
	cmp r2, r8
	beq _0809523C
	movs r0, #1
	movs r6, #0xa
	cmp r2, r8
	ble _0809523C
	movs r6, #0
_0809523C:
	cmp r0, #0
	beq _080952C6
	mov r0, sb
	adds r1, r5, #0
	movs r2, #3
	movs r3, #1
	bl FUN_0808b97c
	mov r3, sb
	lsls r1, r3, #3
	ldr r0, _080952E4 @ =0xFFFF0000
	ldr r2, [sp, #0x5c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x5c]
	lsls r2, r5, #0x13
	ldr r1, _080952E8 @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x58]
	adds r3, #0x60
	mov sl, r3
	adds r6, #0xa
	mov r8, r6
	add r0, sp, #0x28
	mov sb, r0
	ldr r1, [sp, #0x58]
	ldr r2, _080952EC @ =0x0000216C
	adds r4, r1, r2
	ldr r3, _080952F0 @ =0x00002164
	adds r6, r1, r3
	movs r5, #2
_0809527E:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x60]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	mov r1, sb
	adds r1, #4
	mov sb, r1
	subs r1, #4
	ldm r1!, {r2}
	add r2, r8
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, [sp, #0x5c]
	adds r1, #8
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080952E4 @ =0xFFFF0000
	ldr r2, [sp, #0x5c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x5c]
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809527E
_080952C6:
	adds r4, r7, #0
	cmp r4, #3
	bgt _080952CE
	b _08095196
_080952CE:
	add sp, #0x70
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080952E0: .4byte 0x0000F001
_080952E4: .4byte 0xFFFF0000
_080952E8: .4byte 0x0000FFFF
_080952EC: .4byte 0x0000216C
_080952F0: .4byte 0x00002164
