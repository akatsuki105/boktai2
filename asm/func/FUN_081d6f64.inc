	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r5, #0
	mov r6, r8
	adds r6, #0xa0
	movs r0, #1
	mov sb, r0
	movs r7, #0x8e
	lsls r7, r7, #1
_081D6F7C:
	mov r1, sb
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D6F8C
	movs r0, #1
	b _081D6F8E
_081D6F8C:
	movs r0, #0
_081D6F8E:
	cmp r0, #0
	bne _081D6FBE
	adds r0, r7, #0
	bl Malloc
	adds r4, r0, #0
	adds r1, r7, #0
	bl ClearMemory
	mov r1, sb
	lsls r1, r5
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0xfc
	strh r5, [r0]
	lsls r1, r5, #2
	mov r0, r8
	adds r0, #0x20
	adds r0, r0, r1
	str r4, [r0]
	adds r0, r4, #0
	b _081D6FC6
_081D6FBE:
	adds r5, #1
	cmp r5, #0x1f
	ble _081D6F7C
	movs r0, #0
_081D6FC6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
