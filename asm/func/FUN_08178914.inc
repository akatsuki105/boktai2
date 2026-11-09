	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r2, #0
	mov sl, r2
	ldr r7, _08178960 @ =0x00001012
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	bge _08178A22
	movs r6, #0
	ldr r2, _08178964 @ =0x0000076E
	adds r3, r5, r2
	adds r4, r5, #0
	movs r7, #2
	mov sb, r7
	movs r0, #1
	mov r8, r0
	movs r1, #0x92
	lsls r1, r1, #1
	mov ip, r1
_0817894C:
	adds r0, r6, r5
	ldr r2, _08178968 @ =0x00000755
	adds r0, r0, r2
	ldrb r0, [r0]
	mov r7, sb
	ands r0, r7
	cmp r0, #0
	beq _0817896C
	movs r0, #1
	b _0817896E
	.align 2, 0
_08178960: .4byte 0x00001012
_08178964: .4byte 0x0000076E
_08178968: .4byte 0x00000755
_0817896C:
	movs r0, #0
_0817896E:
	cmp r0, #0
	beq _08178A0C
	adds r0, r6, r5
	ldr r1, _08178988 @ =0x00000755
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _0817898C
	movs r0, #1
	b _0817898E
	.align 2, 0
_08178988: .4byte 0x00000755
_0817898C:
	movs r0, #0
_0817898E:
	cmp r0, #0
	bne _08178A0C
	ldr r7, _081789C8 @ =0x00000674
	adds r1, r4, r7
	ldr r0, _081789CC @ =0x0000076C
	adds r2, r4, r0
	ldrh r0, [r2]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldr r0, _081789D0 @ =0x00000676
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
	blt _081789D4
	asrs r1, r0, #1
	b _081789DA
	.align 2, 0
_081789C8: .4byte 0x00000674
_081789CC: .4byte 0x0000076C
_081789D0: .4byte 0x00000676
_081789D4:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_081789DA:
	ldr r2, _081789EC @ =0x0000076C
	adds r0, r4, r2
	strh r1, [r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r0, #0
	blt _081789F0
	asrs r0, r0, #1
	b _081789F6
	.align 2, 0
_081789EC: .4byte 0x0000076C
_081789F0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_081789F6:
	strh r0, [r3]
	movs r1, #2
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _08178A04
	asrs r0, r0, #1
	b _08178A0A
_08178A04:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08178A0A:
	strh r0, [r3, #2]
_08178A0C:
	add r6, ip
	add r3, ip
	add r4, ip
	movs r2, #1
	add sl, r2
	ldr r7, _08178A30 @ =0x00001012
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _0817894C
_08178A22:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08178A30: .4byte 0x00001012
