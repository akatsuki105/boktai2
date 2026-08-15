	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r4, r3, #0
	ldrb r2, [r4]
	movs r1, #0xf0
	ands r1, r2
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0xc0
	bne _082312C6
	movs r0, #9
	str r0, [r6]
	ldrb r0, [r4]
	movs r1, #0xc1
	rsbs r1, r1, #0
	ands r0, r1
	subs r0, #1
	b _0823135C
_082312C6:
	cmp r1, #0
	bne _08231382
	str r2, [r6]
	adds r4, #1
	cmp r2, #0xe
	bls _082312D4
	b _0823142E
_082312D4:
	lsls r0, r2, #2
	ldr r1, _082312E0 @ =_082312E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082312E0: .4byte _082312E4
_082312E4: @ jump table
	.4byte _08231320 @ case 0
	.4byte _08231324 @ case 1
	.4byte _0823135A @ case 2
	.4byte _0823135A @ case 3
	.4byte _0823135A @ case 4
	.4byte _0823142E @ case 5
	.4byte _0823134C @ case 6
	.4byte _08231362 @ case 7
	.4byte _08231324 @ case 8
	.4byte _08231332 @ case 9
	.4byte _08231332 @ case 10
	.4byte _0823142E @ case 11
	.4byte _0823142E @ case 12
	.4byte _08231332 @ case 13
	.4byte _0823136C @ case 14
_08231320:
	movs r4, #0
	b _0823142E
_08231324:
	ldrb r1, [r4, #1]
	lsls r1, r1, #8
	ldrb r0, [r4]
	orrs r0, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b _08231354
_08231332:
	ldrb r1, [r4, #3]
	lsls r1, r1, #0x18
	ldrb r0, [r4, #2]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r4]
	orrs r1, r0
	str r1, [r5]
	adds r4, #4
	b _0823142E
_0823134C:
	ldrb r0, [r4, #1]
	lsls r0, r0, #8
	ldrb r1, [r4]
	orrs r0, r1
_08231354:
	str r0, [r5]
	adds r4, #2
	b _0823142E
_0823135A:
	ldrb r0, [r4]
_0823135C:
	str r0, [r5]
	adds r4, #1
	b _0823142E
_08231362:
	adds r0, r4, #1
	str r0, [r5]
	ldrb r0, [r4]
	adds r0, #1
	b _0823142C
_0823136C:
	ldrb r1, [r4, #1]
	lsls r1, r1, #8
	ldrb r0, [r4]
	orrs r0, r1
	bl Textbox_LookupString
	str r0, [r5]
	movs r0, #7
	str r0, [r6]
	adds r4, #2
	b _0823142E
_08231382:
	str r1, [r6]
	cmp r1, #0x40
	beq _082313C0
	cmp r1, #0x40
	bgt _082313A0
	cmp r1, #0x20
	beq _082313B4
	cmp r1, #0x20
	bgt _0823139A
	cmp r1, #0x10
	beq _082313B4
	b _0823142E
_0823139A:
	cmp r1, #0x30
	beq _08231402
	b _0823142E
_082313A0:
	cmp r1, #0x80
	beq _082313F4
	cmp r1, #0x80
	bgt _082313AE
	cmp r1, #0x50
	beq _08231412
	b _0823142E
_082313AE:
	cmp r1, #0x90
	beq _082313E0
	b _0823142E
_082313B4:
	adds r0, r3, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl ReadMemory
	b _08231430
_082313C0:
	ldrb r0, [r4]
	movs r1, #0xf
	ands r1, r0
	cmp r1, #0xf
	bne _082313D8
	ldrb r0, [r4, #1]
	adds r0, #0xf
	bl VM_ParseParameter
	str r0, [r5]
	adds r4, #1
	b _082313EC
_082313D8:
	adds r0, r1, #0
	bl VM_ParseParameter
	b _082313EA
_082313E0:
	ldrb r1, [r4]
	movs r0, #0xf
	ands r0, r1
	bl VM_GetVariable
_082313EA:
	str r0, [r5]
_082313EC:
	movs r0, #9
	str r0, [r6]
	adds r4, #1
	b _0823142E
_082313F4:
	adds r0, r4, #0
	mov r1, sp
	bl VM_ReadContainerLength
	adds r4, r0, #0
	str r4, [r5]
	b _0823142A
_08231402:
	adds r0, r4, #0
	mov r1, sp
	bl VM_ReadContainerLength
	adds r4, r0, #0
	bl Script_RunExpression
	b _08231428
_08231412:
	adds r0, r4, #0
	mov r1, sp
	bl VM_ReadContainerLength
	adds r4, r0, #0
	ldrb r1, [r4]
	lsls r1, r1, #0x10
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r4, #1
_08231428:
	str r0, [r5]
_0823142A:
	ldr r0, [sp]
_0823142C:
	adds r4, r4, r0
_0823142E:
	adds r0, r4, #0
_08231430:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
