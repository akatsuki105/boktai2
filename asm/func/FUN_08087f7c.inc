	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r3, _08087FBC @ =0x03002BE0
	ldr r0, [r3]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _08087FC0 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x46
	muls r0, r1, r0
	adds r5, r3, #0
	cmp r0, #0
	blt _08087FC4
	asrs r0, r0, #0xc
	b _08087FCA
	.align 2, 0
_08087FBC: .4byte 0x03002BE0
_08087FC0: .4byte gSineTable
_08087FC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08087FCA:
	mov sl, r0
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x46
	muls r0, r1, r0
	cmp r0, #0
	blt _08087FE4
	asrs r0, r0, #0xc
	b _08087FEA
_08087FE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08087FEA:
	adds r7, r0, #0
	ldr r2, [r5]
	movs r3, #0x2c
	ldrsh r0, [r2, r3]
	add r0, sl
	adds r3, r6, #0
	adds r3, #0x48
	movs r4, #0
	ldrsh r1, [r3, r4]
	subs r5, r0, r1
	movs r1, #0x30
	ldrsh r0, [r2, r1]
	adds r0, r0, r7
	adds r2, r6, #0
	adds r2, #0x4c
	movs r4, #0
	ldrsh r1, [r2, r4]
	subs r4, r0, r1
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r4, #0
	muls r0, r4, r0
	adds r1, r1, r0
	ldr r0, _08088048 @ =0x000057E4
	mov r8, r3
	mov sb, r2
	cmp r1, r0
	ble _080880EE
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	adds r4, r0, #0
	ldr r2, _0808804C @ =gSineTable
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08088050
	asrs r0, r0, #0xc
	b _08088056
	.align 2, 0
_08088048: .4byte 0x000057E4
_0808804C: .4byte gSineTable
_08088050:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08088056:
	adds r5, r0, #0
	ldr r1, _08088074 @ =gSineTable
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08088078
	asrs r1, r0, #0xc
	b _0808807E
	.align 2, 0
_08088074: .4byte gSineTable
_08088078:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808807E:
	mov r3, r8
	movs r4, #0
	ldrsh r2, [r3, r4]
	mov r0, sl
	subs r2, r2, r0
	adds r2, r2, r5
	mov r3, sb
	movs r4, #0
	ldrsh r0, [r3, r4]
	subs r0, r0, r7
	adds r4, r0, r1
	ldr r3, _080880AC @ =0x03002BE0
	ldr r0, [r3]
	movs r5, #0x2c
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r2
	adds r5, r3, #0
	cmp r0, #0
	blt _080880B0
	asrs r1, r0, #2
	b _080880B6
	.align 2, 0
_080880AC: .4byte 0x03002BE0
_080880B0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080880B6:
	ldr r0, [r5]
	strh r1, [r0, #0x2c]
	ldr r0, [r5]
	movs r2, #0x30
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r4
	cmp r0, #0
	blt _080880CE
	asrs r1, r0, #2
	b _080880D4
_080880CE:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r1, r0, #0
_080880D4:
	ldr r0, [r5]
	strh r1, [r0, #0x30]
	adds r0, r6, #0
	bl FUN_08087cbc
	ldr r0, [r5]
	movs r3, #0x82
	lsls r3, r3, #1
	adds r2, r0, r3
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_080880EE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
