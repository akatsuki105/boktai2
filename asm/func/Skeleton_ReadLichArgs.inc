	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r1, _0810627C @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	beq _08106248
	b _08106340
_08106248:
	adds r7, r4, #0
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #2
	bne _08106330
	movs r0, #0x4f
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081062BC
	movs r5, #0
	movs r0, #0
	mov r8, r0
	movs r6, #0
_08106268:
	ldr r1, _08106280 @ =0x0000079E
	adds r0, r7, r1
	adds r4, r0, r6
	bl VM_GetPC
	cmp r0, #0
	beq _08106284
	bl VM_GetValue
	b _08106286
	.align 2, 0
_0810627C: .4byte 0x000001DF
_08106280: .4byte 0x0000079E
_08106284:
	movs r0, #0
_08106286:
	strh r0, [r4]
	movs r2, #0xf3
	lsls r2, r2, #3
	adds r0, r7, r2
	adds r4, r0, r6
	bl VM_GetPC
	cmp r0, #0
	beq _0810629E
	bl VM_GetValue
	b _081062A0
_0810629E:
	movs r0, #0
_081062A0:
	strh r0, [r4]
	ldr r1, _081062B8 @ =0x000007A4
	adds r0, r7, r1
	adds r0, r0, r5
	mov r2, r8
	strb r2, [r0]
	adds r6, #2
	adds r5, #1
	cmp r5, #2
	ble _08106268
	b _081062DA
	.align 2, 0
_081062B8: .4byte 0x000007A4
_081062BC:
	movs r5, #0
	movs r6, #0
	movs r2, #0
	ldr r0, _081062F4 @ =0x000007A4
	adds r3, r4, r0
	subs r0, #0xc
	adds r1, r4, r0
_081062CA:
	strh r2, [r1, #6]
	strh r2, [r1]
	adds r0, r3, r5
	strb r6, [r0]
	adds r1, #2
	adds r5, #1
	cmp r5, #2
	ble _081062CA
_081062DA:
	movs r0, #0x54
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0810631C
	bl VM_GetPC
	cmp r0, #0
	beq _081062F8
	bl VM_GetValue
	adds r1, r0, #0
	b _081062FA
	.align 2, 0
_081062F4: .4byte 0x000007A4
_081062F8:
	movs r1, #0
_081062FA:
	ldr r2, _08106310 @ =0x0000071C
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08106314
	bl VM_GetValue
	adds r1, r0, #0
	b _08106316
	.align 2, 0
_08106310: .4byte 0x0000071C
_08106314:
	movs r1, #0
_08106316:
	ldr r2, _08106328 @ =0x0000071E
	adds r0, r7, r2
	strh r1, [r0]
_0810631C:
	ldr r0, _0810632C @ =0x00000755
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	b _08106340
	.align 2, 0
_08106328: .4byte 0x0000071E
_0810632C: .4byte 0x00000755
_08106330:
	movs r0, #0x73
	movs r1, #0
	bl VM_GetNamedArgValue
	movs r2, #0xe4
	lsls r2, r2, #3
	adds r1, r4, r2
	strh r0, [r1]
_08106340:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
