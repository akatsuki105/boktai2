	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	ldr r7, _081E4108 @ =0x00000BC4
	add r7, sl
	add r4, sp, #0x14
	movs r0, #0
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r4, #0
	ldr r2, _081E410C @ =0x05000002
	bl CpuSet
	ldr r0, _081E4110 @ =0x0000CB05
	ldr r1, _081E4114 @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	cmp r1, #0
	bne _081E4086
	b _081E41BE
_081E4086:
	ldr r0, _081E4118 @ =0x0000158C
	add r0, sl
	str r1, [r0]
	ldr r0, _081E411C @ =0x0000156C
	add r0, sl
	bl OpenMainSpriteFile
	movs r5, #0
	mov r8, r5
	ldr r6, _081E4120 @ =0x00000E86
	add r6, sl
	ldr r0, _081E4124 @ =0x00000E4C
	add r0, sl
	mov sb, r0
	adds r4, r7, #0
_081E40A4:
	movs r1, #3
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	mov r1, sp
	strh r0, [r1, #0x14]
	asrs r1, r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	mov r2, sp
	strh r0, [r2, #0x16]
	adds r0, r5, #0
	adds r1, r4, #0
	bl GetWeaponData
	ldrb r2, [r4]
	movs r0, #1
	str r0, [sp]
	movs r3, #0
	str r3, [sp, #4]
	str r3, [sp, #8]
	add r0, sp, #0x14
	str r0, [sp, #0xc]
	mov r0, sb
	ldr r3, _081E4128 @ =0x000009A8
	adds r1, r7, r3
	movs r3, #0x10
	bl MainSprite_Add
	adds r0, r5, #0
	bl IsWeaponSellable
	cmp r0, #0
	bne _081E4130
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r6]
	subs r0, #0x10
	adds r1, r7, r0
	add r1, r8
	ldr r0, _081E412C @ =0x03003584
	ldr r0, [r0]
	movs r2, #0xb8
	lsls r2, r2, #7
	b _081E4142
	.align 2, 0
_081E4108: .4byte 0x00000BC4
_081E410C: .4byte 0x05000002
_081E4110: .4byte 0x0000CB05
_081E4114: .4byte 0x00005D04
_081E4118: .4byte 0x0000158C
_081E411C: .4byte 0x0000156C
_081E4120: .4byte 0x00000E86
_081E4124: .4byte 0x00000E4C
_081E4128: .4byte 0x000009A8
_081E412C: .4byte 0x03003584
_081E4130:
	ldr r0, _081E41D0 @ =0x000002DF
	strh r0, [r6]
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r1, r7, r3
	add r1, r8
	ldr r0, _081E41D4 @ =0x03003584
	ldr r0, [r0]
	ldr r2, _081E41D8 @ =0x00005BE0
_081E4142:
	adds r0, r0, r2
	str r0, [r1]
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r7, r3
	add r0, r8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r0, #0x60
	add r8, r0
	adds r6, #0x60
	add sb, r0
	adds r4, #0x24
	adds r5, #1
	cmp r5, #0xf
	ble _081E40A4
	movs r0, #0x30
	mov r1, sp
	strh r0, [r1, #0x14]
	add r1, sp, #0x14
	movs r0, #0x48
	strh r0, [r1, #2]
	mov sb, r2
	ldr r2, _081E41DC @ =0x00000888
	adds r4, r7, r2
	movs r6, #0xc0
	lsls r6, r6, #3
	movs r3, #0
	mov r8, r3
	movs r5, #1
_081E4182:
	mov r0, sb
	str r0, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r1, [sp, #8]
	add r2, sp, #0x14
	str r2, [sp, #0xc]
	adds r0, r4, #0
	ldr r3, _081E41E0 @ =0x000009A8
	adds r1, r7, r3
	movs r2, #0
	movs r3, #0x10
	bl MainSprite_Add
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r1, r7, r0
	adds r1, r1, r6
	ldr r0, [r1]
	mov r2, sb
	orrs r0, r2
	str r0, [r1]
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E4182
	mov r0, sl
	bl FUN_081e4014
_081E41BE:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E41D0: .4byte 0x000002DF
_081E41D4: .4byte 0x03003584
_081E41D8: .4byte 0x00005BE0
_081E41DC: .4byte 0x00000888
_081E41E0: .4byte 0x000009A8
