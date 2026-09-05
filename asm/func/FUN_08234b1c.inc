	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _08234B38 @ =0x030046A4
	ldr r0, [r0]
	ldrh r5, [r0]
	movs r0, #0x6e
	bl VM_SeekToKeyword
	b _08234BB0
	.align 2, 0
_08234B38: .4byte 0x030046A4
_08234B3C:
	ldr r1, _08234BD0 @ =0x030046A4
	ldr r0, [r1]
	movs r2, #0x89
	lsls r2, r2, #2
	adds r4, r0, r2
	ldr r6, _08234BD4 @ =0x00000D24
	adds r6, r6, r0
	mov sl, r6
	movs r7, #0
	mov sb, r7
	str r1, [sp]
	bl Script_GetValue
	mov r8, r0
	ldr r1, [sp]
	cmp sb, r5
	bge _08234BAE
	mov ip, r1
	adds r2, r5, #0
	movs r3, #0
_08234B64:
	ldrh r0, [r4, #8]
	cmp r8, r0
	beq _08234BA2
	mov r5, ip
	ldr r1, [r5]
	adds r1, r1, r3
	movs r6, #0x89
	lsls r6, r6, #2
	adds r1, r1, r6
	adds r0, r4, #0
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r6, r7}
	stm r1!, {r5, r6, r7}
	ldm r0!, {r5, r7}
	stm r1!, {r5, r7}
	mov r6, ip
	ldr r0, [r6]
	mov r7, sb
	lsls r1, r7, #2
	ldr r5, _08234BD4 @ =0x00000D24
	adds r0, r0, r5
	adds r0, r0, r1
	mov r6, sl
	ldr r1, [r6]
	str r1, [r0]
	adds r3, #0x2c
	movs r7, #1
	add sb, r7
_08234BA2:
	subs r2, #1
	adds r4, #0x2c
	movs r0, #4
	add sl, r0
	cmp r2, #0
	bne _08234B64
_08234BAE:
	mov r5, sb
_08234BB0:
	bl VM_GetPC
	cmp r0, #0
	bne _08234B3C
	ldr r0, _08234BD0 @ =0x030046A4
	ldr r0, [r0]
	strh r5, [r0]
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08234BD0: .4byte 0x030046A4
_08234BD4: .4byte 0x00000D24
