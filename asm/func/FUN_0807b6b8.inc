	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl FUN_0807afe8
	ldr r1, _0807B784 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov r8, r0
	mov sb, r8
	cmp r0, #0
	beq _0807B794
	movs r0, #0xdf
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0xb
	bne _0807B794
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0807B794
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0807B788 @ =0xFFFF0000
	adds r4, r5, #0
	ands r4, r6
	orrs r4, r0
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r1, _0807B78C @ =0x0000FFFF
	ands r4, r1
	adds r6, r4, #0
	orrs r6, r0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r5, r7
	adds r7, r5, #0
	orrs r7, r0
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	mov r2, r8
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	subs r2, r0, r1
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	mov r4, r8
	movs r3, #0x30
	ldrsh r1, [r4, r3]
	subs r5, r0, r1
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r5, #0
	muls r1, r5, r1
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xb
	cmp r0, r1
	bgt _0807B794
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, sb
	ldrb r4, [r0]
	adds r4, #5
	movs r0, #7
	ands r4, r0
	lsls r4, r4, #5
	adds r0, r2, #0
	adds r1, r5, #0
	bl FUN_0823785c
	ldr r1, _0807B790 @ =0xFFFFFF00
	adds r4, r4, r1
	subs r0, r0, r4
	movs r5, #0xff
	ands r0, r5
	subs r0, #0x21
	cmp r0, #0xbe
	bls _0807B794
	movs r0, #0x64
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0807B794
	bl Script_GetValue
	subs r0, r0, r4
	ands r0, r5
	subs r0, #0x21
	cmp r0, #0xbe
	bls _0807B794
	movs r0, #1
	b _0807B796
	.align 2, 0
_0807B784: .4byte 0x03002BE0
_0807B788: .4byte 0xFFFF0000
_0807B78C: .4byte 0x0000FFFF
_0807B790: .4byte 0xFFFFFF00
_0807B794:
	movs r0, #0
_0807B796:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
