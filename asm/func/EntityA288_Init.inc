	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r7, r0, #0
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08219FFE
	bl Script_GetValue
	str r0, [r7, #0x40]
_08219FFE:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A014
	bl FUN_0823d340
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
_0821A014:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A028
	bl FUN_0823d340
	ldr r3, _0821A070 @ =0x00000DAC
	adds r1, r7, r3
	str r0, [r1]
_0821A028:
	movs r0, #0x49
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A0D8
	movs r4, #0xd8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov r8, r4
	bl VM_GetValueSafe2
	movs r2, #0xdb
	lsls r2, r2, #4
	adds r1, r7, r2
	str r0, [r1]
	bl VM_SetPC
	movs r3, #0
	mov sl, r3
	movs r4, #0xf0
	lsls r4, r4, #3
	adds r6, r7, r4
_0821A054:
	bl Script_GetValue
	strb r0, [r6]
	bl Script_GetValue
	strb r0, [r6, #1]
	movs r0, #0
	mov sb, r0
	movs r0, #0x34
	mov r4, sl
	muls r4, r0, r4
	adds r5, r4, #0
	b _0821A0A0
	.align 2, 0
_0821A070: .4byte 0x00000DAC
_0821A074:
	bl VM_GetValueAt
	mov r1, r8
	adds r1, #0xc2
	adds r1, r1, r5
	strh r0, [r1]
	bl Script_GetValue
	mov r1, r8
	adds r1, #0xcc
	adds r1, r1, r4
	str r0, [r1]
	bl Script_GetValue
	mov r1, r8
	adds r1, #0xe0
	adds r1, r1, r4
	str r0, [r1]
	adds r4, #4
	adds r5, #2
	movs r1, #1
	add sb, r1
_0821A0A0:
	movs r0, #1
	ldrsb r0, [r6, r0]
	cmp sb, r0
	bge _0821A0B0
	bl VM_GetPC
	cmp r0, #0
	bne _0821A074
_0821A0B0:
	movs r0, #0
	ldrsb r0, [r6, r0]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, r2
	bne _0821A0CC
	mov r1, sl
	subs r1, #1
	ldr r0, _0821A0C8 @ =0x000006F6
	add r0, r8
	strh r1, [r0]
	b _0821A0D8
	.align 2, 0
_0821A0C8: .4byte 0x000006F6
_0821A0CC:
	adds r6, #0x34
	movs r3, #1
	add sl, r3
	mov r4, sl
	cmp r4, #0x1d
	ble _0821A054
_0821A0D8:
	movs r0, #0x62
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A0EC
	bl FUN_0823d340
	ldr r2, _0821A250 @ =0x000012AC
	adds r1, r7, r2
	str r0, [r1]
_0821A0EC:
	movs r0, #0x67
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A100
	bl FUN_0823d340
	ldr r3, _0821A254 @ =0x00001650
	adds r1, r7, r3
	str r0, [r1]
_0821A100:
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A114
	bl VM_GetPC
	ldr r4, _0821A258 @ =0x0000178C
	adds r1, r7, r4
	str r0, [r1]
_0821A114:
	movs r0, #0x53
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A128
	bl FUN_0823d340
	ldr r2, _0821A25C @ =0x00001790
	adds r1, r7, r2
	str r0, [r1]
_0821A128:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A13C
	bl VM_GetPC
	ldr r3, _0821A260 @ =0x00001794
	adds r1, r7, r3
	str r0, [r1]
_0821A13C:
	movs r0, #0x4e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A150
	bl VM_GetPC
	ldr r4, _0821A264 @ =0x00001798
	adds r1, r7, r4
	str r0, [r1]
_0821A150:
	movs r0, #0x48
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A164
	bl FUN_0823d340
	ldr r2, _0821A268 @ =0x0000179C
	adds r1, r7, r2
	str r0, [r1]
_0821A164:
	movs r0, #0x4b
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A17A
	bl FUN_0823d340
	movs r3, #0xbd
	lsls r3, r3, #5
	adds r1, r7, r3
	str r0, [r1]
_0821A17A:
	movs r0, #0x54
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A18E
	bl FUN_0823d340
	ldr r4, _0821A26C @ =0x00001654
	adds r1, r7, r4
	str r0, [r1]
_0821A18E:
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A1A2
	bl FUN_0823d340
	ldr r2, _0821A270 @ =0x00001658
	adds r1, r7, r2
	str r0, [r1]
_0821A1A2:
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A1B8
	bl FUN_0823d340
	movs r3, #0xe8
	lsls r3, r3, #4
	adds r1, r7, r3
	str r0, [r1]
_0821A1B8:
	movs r0, #0x45
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A1CC
	bl Script_GetValue
	ldr r4, _0821A274 @ =0x00000E88
	adds r1, r7, r4
	str r0, [r1]
_0821A1CC:
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A1DC
	bl Script_GetValue
	str r0, [r7, #0x48]
_0821A1DC:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A1EC
	bl Script_GetValue
	str r0, [r7, #0x4c]
_0821A1EC:
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0821A1FC
	bl Script_GetValue
	str r0, [r7, #0x50]
_0821A1FC:
	movs r1, #0
	str r1, [r7, #0x44]
	str r1, [r7, #0x54]
	str r1, [r7, #0x58]
	str r1, [r7, #0x5c]
	str r1, [r7, #0x60]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r7, #0x64]
	str r1, [r7, #0x68]
	adds r0, r7, #0
	bl FUN_08219e5c
	adds r0, r7, #0
	bl FUN_08219e9c
	adds r0, r7, #0
	bl FUN_08219ed0
	mov r1, sp
	ldr r0, _0821A278 @ =0x08252850
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	ldr r0, [r7, #0x40]
	lsls r0, r0, #2
	add r0, sp
	ldr r1, [r0]
	adds r0, r7, #0
	bl FUN_08219f34
	movs r0, #0
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0821A250: .4byte 0x000012AC
_0821A254: .4byte 0x00001650
_0821A258: .4byte 0x0000178C
_0821A25C: .4byte 0x00001790
_0821A260: .4byte 0x00001794
_0821A264: .4byte 0x00001798
_0821A268: .4byte 0x0000179C
_0821A26C: .4byte 0x00001654
_0821A270: .4byte 0x00001658
_0821A274: .4byte 0x00000E88
_0821A278: .4byte 0x08252850
