	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08243660
FUN_08243660: @ 0x08243660
	push {r4, r5, r6, lr}
	ldr r1, _082436B8 @ =0x03004880
	ldr r6, _082436BC @ =0x03003518
	ldr r0, [r6]
	str r0, [r1]
	ldr r5, _082436C0 @ =0x03002CA0
	ldr r0, [r5]
	str r0, [r1, #4]
	ldr r3, _082436C4 @ =0x03003510
	ldrh r0, [r3]
	movs r4, #0
	strh r0, [r1, #8]
	ldr r2, _082436C8 @ =0x03003514
	ldrh r0, [r2]
	strh r0, [r1, #0xa]
	str r4, [r6]
	str r4, [r5]
	strh r4, [r3]
	strh r4, [r2]
	bl FUN_082407e0
	bl FUN_08229f34
	ldr r0, _082436CC @ =0x0300351C
	strh r4, [r0]
	bl m4aSoundVSyncOff
	bl FUN_08229f34
	ldr r3, _082436D0 @ =0x04000208
	strh r4, [r3]
	ldr r2, _082436D4 @ =0x0300170C
	ldr r1, _082436D8 @ =0x0300481C
	ldr r0, [r1]
	str r0, [r2]
	movs r0, #1
	str r0, [r1]
	strh r0, [r3]
	bl FUN_08241704
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_082436B8: .4byte 0x03004880
_082436BC: .4byte 0x03003518
_082436C0: .4byte 0x03002CA0
_082436C4: .4byte 0x03003510
_082436C8: .4byte 0x03003514
_082436CC: .4byte 0x0300351C
_082436D0: .4byte 0x04000208
_082436D4: .4byte 0x0300170C
_082436D8: .4byte 0x0300481C

	thumb_func_start FUN_082436dc
FUN_082436dc: @ 0x082436DC
	push {r4, r5, lr}
	ldr r4, _08243724 @ =0x03004880
	ldr r0, _08243728 @ =0x04000202
	movs r5, #1
	strh r5, [r0]
	ldr r0, _0824372C @ =0x0300351C
	strh r5, [r0]
	bl m4aSoundVSyncOn
	bl FUN_08229f34
	ldr r2, _08243730 @ =0x04000208
	movs r0, #0
	strh r0, [r2]
	ldr r1, _08243734 @ =0x03003518
	ldr r0, [r4]
	str r0, [r1]
	ldr r1, _08243738 @ =0x03002CA0
	ldr r0, [r4, #4]
	str r0, [r1]
	ldr r1, _0824373C @ =0x03003510
	ldrh r0, [r4, #8]
	strh r0, [r1]
	ldr r1, _08243740 @ =0x03003514
	ldrh r0, [r4, #0xa]
	strh r0, [r1]
	ldr r1, _08243744 @ =0x0300481C
	ldr r0, _08243748 @ =0x0300170C
	ldr r0, [r0]
	str r0, [r1]
	strh r5, [r2]
	bl FUN_0824172c
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08243724: .4byte 0x03004880
_08243728: .4byte 0x04000202
_0824372C: .4byte 0x0300351C
_08243730: .4byte 0x04000208
_08243734: .4byte 0x03003518
_08243738: .4byte 0x03002CA0
_0824373C: .4byte 0x03003510
_08243740: .4byte 0x03003514
_08243744: .4byte 0x0300481C
_08243748: .4byte 0x0300170C

	thumb_func_start FUN_0824374c
FUN_0824374c: @ 0x0824374C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r1
	mov r8, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	asrs r7, r2, #3
	mov r4, sb
	mov r5, sl
	movs r6, #0
	cmp r6, r7
	bge _08243788
_0824376E:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl EEPROMWrite1
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08243814
	adds r4, #8
	adds r5, #1
	adds r6, #1
	cmp r6, r7
	blt _0824376E
_08243788:
	mov r4, sb
	mov r5, sl
	movs r6, #0
	cmp r6, r7
	bge _082437AC
_08243792:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl EEPROMCompare
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08243814
	adds r4, #8
	adds r5, #1
	adds r6, #1
	cmp r6, r7
	blt _08243792
_082437AC:
	mov r0, sp
	movs r1, #0
	strh r1, [r0]
	strh r1, [r0, #2]
	mov r1, r8
	asrs r0, r1, #1
	lsls r7, r5, #0x10
	cmp r0, #0
	ble _082437E0
	mov r4, sp
	mov r1, sb
	ldrh r3, [r4]
	movs r5, #0
	adds r6, r0, #0
_082437C8:
	ldrh r0, [r1]
	adds r2, r3, #0
	eors r2, r0
	adds r3, r2, #0
	adds r0, r5, r0
	adds r5, r0, #0
	adds r1, #2
	subs r6, #1
	cmp r6, #0
	bne _082437C8
	strh r0, [r4, #2]
	strh r2, [r4]
_082437E0:
	mov r0, sp
	mov r1, r8
	strh r1, [r0, #4]
	mov r1, sp
	ldr r0, _08243810 @ =0x0000FFFF
	strh r0, [r1, #6]
	lsrs r4, r7, #0x10
	adds r0, r4, #0
	bl EEPROMWrite1
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08243814
	adds r0, r4, #0
	mov r1, sp
	bl EEPROMCompare
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08243814
	movs r0, #8
	add r8, r0
	mov r0, r8
	b _08243818
	.align 2, 0
_08243810: .4byte 0x0000FFFF
_08243814:
	movs r0, #1
	rsbs r0, r0, #0
_08243818:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08243828
FUN_08243828: @ 0x08243828
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r1, #0
	mov r8, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r7, r2, #3
	mov sb, r5
	movs r6, #0
	cmp r6, r7
	bge _08243860
_08243844:
	adds r0, r4, #0
	adds r1, r5, #0
	bl EEPROMRead
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _082438C8
	adds r5, #8
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r6, #1
	cmp r6, r7
	blt _08243844
_08243860:
	adds r0, r4, #0
	mov r1, sp
	bl EEPROMRead
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _082438C8
	add r0, sp, #8
	strh r5, [r0]
	strh r5, [r0, #2]
	mov r1, r8
	asrs r2, r1, #1
	adds r7, r0, #0
	cmp r5, r2
	bge _082438A4
	mov ip, r7
	movs r4, #0
	movs r3, #0
	mov r1, sb
	adds r6, r2, #0
_0824388A:
	ldrh r0, [r1]
	adds r2, r4, #0
	eors r2, r0
	adds r4, r2, #0
	adds r0, r3, r0
	adds r3, r0, #0
	adds r1, #2
	subs r6, #1
	cmp r6, #0
	bne _0824388A
	mov r1, ip
	strh r0, [r1, #2]
	strh r2, [r1]
_082438A4:
	mov r0, sp
	ldrh r1, [r7]
	ldrh r0, [r0]
	eors r1, r0
	strh r1, [r7]
	cmp r5, #0
	bne _082438C8
	cmp r1, #0
	bne _082438C8
	mov r0, sp
	ldrh r1, [r7, #2]
	ldrh r0, [r0, #2]
	cmp r1, r0
	bne _082438C8
	mov r0, sp
	ldrh r0, [r0, #4]
	cmp r8, r0
	beq _082438CE
_082438C8:
	movs r0, #1
	rsbs r0, r0, #0
	b _082438D0
_082438CE:
	movs r0, #0
_082438D0:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082438e0
FUN_082438e0: @ 0x082438E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r7, r1, #3
	add r0, sp, #8
	movs r1, #0
	strh r1, [r0]
	strh r1, [r0, #2]
	movs r5, #0
	mov r8, r0
	cmp r5, r7
	bge _08243940
	add r0, sp, #0xc
	mov sb, r0
_08243908:
	adds r0, r4, #0
	add r1, sp, #0xc
	bl EEPROMRead
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08243970
	adds r6, r4, #1
	adds r5, #1
	mov r2, r8
	mov r3, sb
	movs r4, #3
_08243920:
	ldrh r0, [r2]
	ldrh r1, [r3]
	eors r0, r1
	strh r0, [r2]
	ldrh r0, [r2, #2]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r2, #2]
	adds r3, #2
	subs r4, #1
	cmp r4, #0
	bge _08243920
	lsls r0, r6, #0x10
	lsrs r4, r0, #0x10
	cmp r5, r7
	blt _08243908
_08243940:
	adds r0, r4, #0
	mov r1, sp
	bl EEPROMRead
	lsls r0, r0, #0x10
	mov r1, sp
	mov r3, r8
	ldrh r2, [r3]
	ldrh r1, [r1]
	eors r2, r1
	strh r2, [r3]
	cmp r0, #0
	bne _08243970
	cmp r2, #0
	bne _08243970
	mov r0, sp
	ldrh r1, [r3, #2]
	ldrh r0, [r0, #2]
	cmp r1, r0
	bne _08243970
	mov r0, sp
	ldrh r0, [r0, #4]
	cmp sl, r0
	beq _08243976
_08243970:
	movs r0, #1
	rsbs r0, r0, #0
	b _08243978
_08243976:
	movs r0, #0
_08243978:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08243988
FUN_08243988: @ 0x08243988
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	adds r6, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	bne _082439B0
	adds r0, r6, #0
	bl FUN_08243648
	cmp r6, r0
	bne _082439B0
	ldr r0, _082439B8 @ =0x00001FF8
	cmp r6, r0
	ble _082439BC
_082439B0:
	movs r0, #1
	rsbs r0, r0, #0
	b _082439E4
	.align 2, 0
_082439B8: .4byte 0x00001FF8
_082439BC:
	bl FUN_08243660
	movs r4, #1
	rsbs r4, r4, #0
	movs r5, #0
	b _082439CA
_082439C8:
	adds r5, #1
_082439CA:
	cmp r5, #7
	bgt _082439DE
	mov r0, r8
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_0824374c
	adds r4, r0, #0
	cmp r4, #0
	blt _082439C8
_082439DE:
	bl FUN_082436dc
	adds r0, r4, #0
_082439E4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082439f0
FUN_082439f0: @ 0x082439F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	adds r6, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	bne _08243A18
	adds r0, r6, #0
	bl FUN_08243648
	cmp r6, r0
	bne _08243A18
	ldr r0, _08243A20 @ =0x00001FF8
	cmp r6, r0
	ble _08243A24
_08243A18:
	movs r0, #1
	rsbs r0, r0, #0
	b _08243A4C
	.align 2, 0
_08243A20: .4byte 0x00001FF8
_08243A24:
	bl FUN_08243660
	movs r4, #1
	rsbs r4, r4, #0
	movs r5, #0
	b _08243A32
_08243A30:
	adds r5, #1
_08243A32:
	cmp r5, #7
	bgt _08243A46
	mov r0, r8
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_08243828
	adds r4, r0, #0
	cmp r4, #0
	blt _08243A30
_08243A46:
	bl FUN_082436dc
	adds r0, r4, #0
_08243A4C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08243a58
FUN_08243a58: @ 0x08243A58
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	bl FUN_08243648
	cmp r4, r0
	bne _08243A70
	ldr r0, _08243A78 @ =0x00001FF8
	cmp r4, r0
	ble _08243A7C
_08243A70:
	movs r0, #1
	rsbs r0, r0, #0
	b _08243A90
	.align 2, 0
_08243A78: .4byte 0x00001FF8
_08243A7C:
	bl FUN_08243660
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_082438e0
	adds r4, r0, #0
	bl FUN_082436dc
	adds r0, r4, #0
_08243A90:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

